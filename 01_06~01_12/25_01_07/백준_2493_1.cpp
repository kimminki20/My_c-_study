//백준 2493 탑 다시 도전
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int solution(stack<int> st) {
    if (st.empty()) {
        return 0; // 스택이 비어 있으면 0 반환
    }
    int num = st.top(); // 현재 스택의 맨 위 값
    st.pop();

    while (!st.empty()) { // 스택이 빌 때까지 반복
        if (num < st.top()) {
            return st.size(); // num보다 큰 값이 있으면 현재 스택 크기 반환
        } else {
            st.pop(); // num보다 작거나 같으면 제거
        }
    }
    return 0; // 끝까지 num보다 큰 값이 없으면 0 반환
}
int main(){
    int N;
    cin >> N; //높이 입력하는 순서
    stack<int> st;
    vector<int> result;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        st.push(num); //스택에 값을 넣음
    }
    for(int i=0; i<N; i++){
        if(!st.empty()){
        result.push_back(solution(st));
        st.pop();
        }
    }
    reverse(result.begin(),result.end());
    for(const int ans : result){
        cout << ans << " ";
    }
} //이렇게 해도 시간 초과 발생