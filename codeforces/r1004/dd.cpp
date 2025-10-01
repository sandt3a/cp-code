#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        if (!(cin >> n))
            return 0;

        vector<int> x(n + 1);
        vector<bool> cnt(n + 1, false);

        // 读取输入并记录出现的数
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (x[i] >= 1 && x[i] <= n)
                cnt[x[i]] = true;
        }

        int candidate = -1;
        
        // 找出没有出现的数
        for (int v = 1; v <= n; v++) {
            if (!cnt[v]) {
                candidate = v;
                break;
            }
        }

        if (candidate != -1) {
            // 如果找到了候选数，询问与另一个数的关系
            int other = (candidate == 1 ? 2 : 1);
            cout << "? " << candidate << " " << other << "\n" << flush;
            
            int response;
            cin >> response;
            if (response == -1) return 0;
            
            // 输出结果
            cout << (response == 0 ? "! A" : "! B") << "\n" << flush;

        } else {
            // 如果没有找到候选数，进行差值比较
            int i_min = 1, i_max = 1;
            for (int i = 1; i <= n; i++) {
                if (x[i] < x[i_min])
                    i_min = i;
                if (x[i] > x[i_max])
                    i_max = i;
            }

            int diff = abs(x[i_min] - x[i_max]);

            // 询问这两个位置的差值
            cout << "? " << i_min << " " << i_max << "\n" << flush;
            int r;
            cin >> r;
            if (r == -1) return 0;

            // 根据返回值决定输出
            if (r < diff) {
                cout << "! A" << "\n" << flush;
            } else if (r > diff) {
                cout << "! B" << "\n" << flush;
            } else {
                // 如果差值相等，交换位置再询问
                cout << "? " << i_max << " " << i_min << "\n" << flush;
                int r2;
                cin >> r2;
                if (r2 == -1) return 0;

                cout << (r2 == diff ? "! B" : "! A") << "\n" << flush;
            }
        }
    }

    return 0;
}
