#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st; // int 타입의 스택 생성

    //push() : 요소를 스택 맨 위에 추가. 시간 복잡도 O(1)
    st.push(10); // 10
    st.push(20); // 10, 20
    st.push(30); // 10, 20, 30

    while(!st.empty()){
        cout << st.top() << " "; // 현재 스택의 맨 위 요소 출력
        st.pop(); // 출력한 요소 제거
    }
    cout << endl; // 줄바꿈
    return 0;
} 
/*
    가장 베이직한 스택의 구조 구현
*/