//백준 1927 최소 힙
#include <iostream>
#include <queue>
using namespace std;            

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
// 최소 힙을 구현하기 위해 priority_queue를 사용
// priority_queue<int> q;	// 내림차순 
// priority_queue<int, vector<int>, less<int> > q;	// 내림차순
//priority_queue<int, vector<int>, greater<int> > q;	// 오름차순
int main(){
    init();
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    int N; //연산의 수
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
    return 0;
}