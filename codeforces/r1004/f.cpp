#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

class Solve{
    vector<ll> P, Q, R;
    vector<int> a;
    int n;
    ll addMod(ll a, ll b){
        return (a + b) % MOD;
    }
    ll mulMod(ll a, ll b){
        return (a * b) % MOD;
    }
    map<tuple<int, ll, ll, ll>, ll> dp;
    ll solve(int pos, ll p, ll q, ll r){
        if (pos == n)return (p == q || q == r || r == p) ? 1 : 0;
        auto state = make_tuple(pos, p, q, r);
        if (dp.count(state))
            return dp[state];
        ll res = 0;
        ll newP = p ^ a[pos];
        if (newP == q || newP == r || q == r)
            res = addMod(res, solve(pos + 1, newP, q, r));
        ll newQ = q ^ a[pos];
        if (p == newQ || newQ == r || p == r)
            res = addMod(res, solve(pos + 1, p, newQ, r));
        ll newR = r ^ a[pos];
        if (p == q || q == newR || p == newR)
            res = addMod(res, solve(pos + 1, p, q, newR));
        return dp[state] = res;
    }
public:
    ll countv(vector<int> &arr){
        a = arr;
        n = a.size();
        dp.clear();
        return solve(0, 0, 0, 0);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        Solve b;
        cout << b.countv(a) << '\n';
    }
}
