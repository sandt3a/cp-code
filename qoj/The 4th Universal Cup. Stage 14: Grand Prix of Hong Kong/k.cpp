
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(2 * n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    std::vector<int> r(2 * n, 2 * n);
    std::vector<int> st;
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }
        r[i] = (st.empty()) ? (2 * n) : st.back();
        st.push_back(i);
    }
    
    int m = *std::min_element(a.begin(), a.end());
    std::vector<int> cand;
    for (int i = 0; i < n; ++i) {
        if (a[i] == m) {
            cand.push_back(i);
        }
    }
    std::vector<int> ans;
    while (ans.size() < n) {
        int x = 0, y = n + 1;
        for (int i : cand) {
            x = std::max(x, r[i] - i);
            if (r[i] != 2 * n) {
                y = std::min(y, a[r[i]]);
            }
        }
        for (int i = 0; i < x && ans.size() < n; ++i) {
            ans.push_back(a[cand[0]]);
        }
        if (ans.size() == n) {
            break;
        }
        std::vector<int> ncand;
        for (int i : cand) {
            if (r[i] - i == x && a[r[i]] == y) {
                ncand.push_back(r[i]);
            }
        }
        cand = ncand;
        std::cout << "x="<<x<<"y="<<y<<std::endl;
        if (cand.size() == 0) {
            break;
        }
    }

    static int T = 0;
    std::cout << "T="<<++T<<std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
