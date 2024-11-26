//10진수를 2진수로 바꾸기(stack 이용)
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution (int dec){
    if(dec == 0)
        return "0"; // 입력이 0이면 0 반환
    stack<int> stack;
    while(dec > 0){
        stack.push(dec % 2); // 2로 나눈 값을 스택에 저장 (0 or 1)
        dec /= 2;
    }
    string binary = "";
    while(!stack.empty()){
        binary += to_string(stack.top()); //to_string 함수는 숫자 타입의 데이터를 안전하게 스트링 타입으로 변경
        stack.pop();
    }
    return binary;
}

// 정수 N을 2진수로 변환하는 경우 N을 2진수로 변환하는 과정은 N이 1이 될 때까지 2로 계속 나누므로 시간복잡도 O(log N).