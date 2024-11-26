//괄호 짝맞추기 문제 -> 스택으로 구현
/* 제약조건
    1.열린 괄호는 자신과 가장 가까운 닫힌 괄호를 만나면 상쇄
    2.모든 괄호가 상쇄되어 더 이상 아무 괄호가 없어야만 정상이라 출력
    3.상쇄할 괄호가 없을 때까지 반복
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution (string s){
    stack<char> stack;

    for(char c: s){
        if(c == '('){
        stack.push(c); // '(' 괄호를 스택에 push
    }
    else if(c == ')'){
        if(stack.empty()){ //')' 괄호가 나오면 스택이 비어 있는지 확인
            return false; // 스택이 비어 있는데  짝이 맞지않으므로 false 반환
        }else {
            stack.pop(); // 비어 있지 않다면 pop (여는 괄호를 스택에서 제거)
            }
        }
    }
     return stack.empty(); //스택이 비어 있따면 괄호가 올바르게 닫힌 것 따라서  true, 아니면 false 반환
}

