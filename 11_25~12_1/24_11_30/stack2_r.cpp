#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 최적화
    cin.tie(0);

    int N, a, num;
    cin >> N;
    stack<int> st;

    while (N--) {
        cin >> a;
        if (a == 1) {
            cin >> num;
            st.push(num);
        } else if (a == 2) {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            } else {
                cout << "-1\n";
            }
        } else if (a == 3) {
            cout << st.size() << '\n';
        } else if (a == 4) {
            cout << (st.empty() ? "1\n" : "0\n");
        } else if (a == 5) {
            if (!st.empty()) {
                cout << st.top() << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}
