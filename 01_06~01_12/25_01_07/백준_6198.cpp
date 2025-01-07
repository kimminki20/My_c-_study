//백준 6198 옥상정원 꾸미기
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N; // 빌딩의 개수를 입력
    vector<int> building(N);
    
    for (int i = 0; i < N; i++) {
        cin >> building[i];
    }

    stack<int> s; // 스택 선언
    long long result = 0; // 결과값 (큰 값 가능성 대비 long long)

    for (int i = 0; i < N; i++) {
        // 스택의 top이 현재 건물보다 작거나 같으면 pop
        while (!s.empty() && s.top() <= building[i]) {
            s.pop();
        }
        // 스택 크기만큼 현재 건물이 볼 수 있는 옥상 개수 추가
        result += s.size();
        // 현재 건물을 스택에 추가
        s.push(building[i]);
    }

    cout << result << endl;
    return 0;
}
