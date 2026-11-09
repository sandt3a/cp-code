#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void send()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<array<int, 2>> e;

    int X = 1;
    int Y;
    if (ranges::count(s, '1') == 0) {
        e.push_back({1, 2});
        e.push_back({2, 3});
        e.push_back({3, 1});
        for (int i = 4; i <= n; i++) {
            e.push_back({1, i});
        }
        goto end;
    }

    for (int i = 2; i <= n; i++) {
        if (s[i - 2] == '1') {
            Y = i;
            break;
        }
    }

    e.push_back({X, Y});
    for (int i = 2; i <= n; i++) {
        if (i == Y) continue;
        if (s[i - 2] == '1') {
            e.push_back({X, i});
        } else {
            e.push_back({Y, i});
        }
    }

end:
    int m = (int)e.size();
    cout << m << "\n";
    for (auto [x, y]: e) {
        cout << x << " " << y << "\n";
    }
}

void receive()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> col(n + 1, -1);
    int flag = 0;

    auto dfs = [&](this auto &&self, int x, int c) -> void {
        col[x] = c;
        for (auto y: e[x]) {
            if (col[y] == col[x]) {
                flag = 1;
                return;
            }
            if (col[y] == -1) {
                self(y, c^1);
            }
            if (flag == 1) {
                return;
            }
        }
    };

    dfs(1, 0);

    string s(n - 1, '0');
    if (flag == 0) {
        for (int i = 2; i <= n; i++) {
            s[i - 2] = char((col[i] ^ col[1]) + '0');
        }
    }
    cout << s << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string run;
    cin >> run;

    int t;
    cin >> t;
    while (t--) {
        if (run == "first") {
            send();
        } else {
            receive();
        }
    }
    return 0;
}
