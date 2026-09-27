#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

template<class F>
struct y_comb {
    F f;
    template<class... Args>
    decltype(auto) operator()(Args&&... args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
template<class F> y_comb(F) -> y_comb<F>;

void solve()
{
    int n;
    cin >> n;

    int tot = (1 << n) - 1;
    cout << tot << endl;

    auto print = y_comb{[&](auto&& self, int x, int a, int b, int c) { // move x from a to c
        if (x == 0) {
            return;
        }
        self(x - 1, a, c, b);
        cout << a << " " << c << endl;
        self(x - 1, b, a, c);
    }};
    
    print(n, 1, 2, 3);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
