#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    std::function<vector<string>(int)> build = [&](int x) -> vector<string> {
        vector<string> code;
        if (x == 1) {
            code = {"0", "1"};
            return code;
        }

        auto p = build(x - 1);
        for (auto s: p) {
            code.push_back("0" + s);
        }
        reverse(p.begin(), p.end());
        for (auto s: p) {
            code.push_back("1" + s);
        }
        return code;
    };

    auto code = build(n);
    for (auto s: code) {
        cout << s << "\n";
    }
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
