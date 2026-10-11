#include <bits/stdc++.h>
#include <cassert>
using namespace std;

vector<int> primes;
vector<int> base;
vector<int> nums;
vector<int> rnk;

constexpr int S = 140;

void init()
{
    constexpr int n = 1000000;

    vector<bool> vis(n + 1);

    for (int i = 2; ; i++) {
        if (!vis[i]) {
            primes.push_back(i);
            if ((int)primes.size() >= S) {
                break;
            }
        }
        for (int j = i << 1; j <= n; j += i) {
            vis[j] = true;
        }
    }

    base = primes;
    for (int i = 0; i < S; i++) {
        while (base[i] * primes[i] <= n) {
            base[i] *= primes[i];
        }
    }

    auto dfs = [&](this auto &&self, int x, int mul) {
        if (x == S) {
            nums.push_back(mul);
            return;
        }

        if (mul * primes[x] <= n) {
            self(x, mul * primes[x]);
        }
        self(x + 1, mul);
    };

    dfs(0, 1);

    rnk.assign(n + 1, 0);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size(); i++) {
        rnk[nums[i]] = i;
    }
}

void send()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> bits(n * 20 + 150);
    for (int i = 0; i < n; i++) {
        for (int j = 19; j >= 0; j--) {
            bits[i * 20 + 19 - j] = a[i] >> j & 1;
        }
    }

    vector<int> b = base;
    for (int i = 0; i < n * 20 / 18 + 1; i++) {
        int y = 0;
        for (int j = 0; j < 18; j++) {
            y = y << 1 | bits[i * 18 + j];
        }
        b.push_back(nums[y]);
    }
    int k = (int)b.size();
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << b[i] << " \n"[i == k - 1];
    }
}

void receive()
{
    int n, k;
    cin >> n >> k;

    auto query = [&](int x, int y) {
        assert(x != y);
        cout << "? " << x + 1 << " " << y + 1 << endl;
        int res;
        cin >> res;
        return res;
    };

    vector<int> bits;
    for (int i = S; i < k; i++) {
        int x = 1;
        for (int j = 0; j < S; j++) {
            x *= query(j, i);
        }
        int y = rnk[x];
        for (int j = 17; j >= 0; j--) {
            bits.push_back(y >> j & 1);
        }
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < 20; j++) {
            if (i * 20 + j >= (int)bits.size()) {
                break;
            }
            x = x << 1 | bits[i * 20 + j];
        }
        a[i] = x;
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    string type;
    cin >> type;
    int t = 1;
    cin >> t;
    while (t--) {
        if (type == "first") {
            send();
        } else if (type == "second") {
            receive();
        } else {
            assert(false);
        }
    }
    return 0;
}
