    #include <bits/stdc++.h>
    using namespace std;

    std::vector<int> minp, primes;

    void sieve(int n) 
    {
        minp.assign(n + 1, 0);

        for (int x = 2; x <= n; x++) {
            if (!minp[x]) {
                minp[x] = x;
                primes.push_back(x);
            }

            for (auto p: primes) {
                if (1ll * x * p > n) break;
                minp[x * p] = p;
                if (minp[x] == p) break;
            }
        }
    }

    void solve()
    {
        int n;
        cin >> n;

        vector<int> p(n + 1);
        vector<int> vis(n + 1);

        iota(p.begin(), p.end(), 0);
        for (int i = n; i >= 2; i--) {
            if (minp[i] == i) {
                vector<int> vec;
                for (int j = i; j <= n; j += i) {
                    if (!vis[j]) {
                        vis[j] = i;
                        vec.push_back(p[j]);
                    }
                }
                // for (auto x:vec) {
                //     cout<<x<<" ";
                // }cout<<endl;
                rotate(vec.begin(), vec.begin() + 1, vec.end());
                for (int j = i, st = 0; j <= n; j += i) {
                    if (vis[j] == i) {
                        p[j] = vec[st++];
                    }
                }
            }
        }

        // int cnt = 0;
        // for (int i = 1; i <= n; i++) {
        //     if (p[i] == i) {
        //         cout<<i<<endl;
        //         ++cnt;
        //     }
        // }
        // cout << "cnt="<<cnt<<endl;

        for (int i = 1; i <= n; i++) {
            cout << p[i] << " \n"[i == n];
        }
    }

    int main()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        sieve(100000);

        int t;
        cin >> t;
        while (t--) {
            solve();
        }
        return 0;
    }
