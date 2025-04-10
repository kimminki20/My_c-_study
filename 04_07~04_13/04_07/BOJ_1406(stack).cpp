//백준 1406 에디터
//https://www.acmicpc.net/problem/1406
/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    string s;
    cin >> s;
    vector<string> st;
    for (int i = 0; i < s.size(); i++) {
        st.push_back(s.substr(i, 1));
    } // 문자열을 한 글자씩 나눠서 저장

    int N;
    cin >> N;
    int cursor = s.size(); // 커서 위치

    while (N--) {
        char c;
        cin >> c;
        if (c == 'L') { // 커서를 왼쪽으로 이동
            if (cursor > 0) {
                cursor--;}}
        else if (c == 'D') { // 커서를 오른쪽으로 이동
            if (cursor < st.size()) {
                cursor++;}}
        else if (c == 'B') { // 커서 왼쪽에 있는 글자 삭제
            if (cursor > 0) {
                st.erase(st.begin() + cursor - 1);
                cursor--;}}
        else if (c == 'P') { // 커서 왼쪽에 글자 삽입
            char x;
            cin >> x;
            st.insert(st.begin() + cursor, string(1, x));
            cursor++;}
    }
    for (string i : st) {
        cout << i;
    }
    return 0;
}
시간 초과 발생    
*/
#include <iostream>     
#include <stack>        
#include <string>       

using namespace std;

int main() {
    string s = "";      
    cin >> s;           
    stack<char> l;      // 커서 기준 왼쪽 문자들을 담을 스택
    stack<char> r;      // 커서 기준 오른쪽 문자들을 담을 스택 -> 이렇게 2개를 선언하는게 핵심.

    for (int i = 0; i < s.size(); i++) {
        l.push(s[i]); //왼쪽에만 담아서 커서가 있는 것처럼 선언
    }
    int num;            // 명령어 개수
    cin >> num;
    while (num--) {
        char tmp;       // 명령어 종류
        cin >> tmp;
        if (tmp == 'P') {           // 문자 추가 명령
            char c;
            cin >> c;
            l.push(c);             // 커서 왼쪽에 문자 삽입
        }
        else if (tmp == 'L') {      // 커서를 왼쪽으로 이동
            if (l.empty()) continue; // 왼쪽이 비어있으면 무시
            r.push(l.top());        // 왼쪽의 맨 위 문자를 오른쪽으로 이동
            l.pop();
        }
        else if (tmp == 'B') {      // 왼쪽 문자 삭제
            if (l.empty()) continue; // 왼쪽이 비어있으면 무시
            l.pop();                // 왼쪽 스택에서 문자 삭제
        }
        else if (tmp == 'D') {      // 커서를 오른쪽으로 이동
            if (r.empty()) continue; // 오른쪽이 비어있으면 무시
            l.push(r.top());        // 오른쪽의 맨 위 문자를 왼쪽으로 이동
            r.pop();
        }
    }
    // 왼쪽 스택의 내용을 오른쪽으로 모두 옮기기 (출력 순서를 위해)
    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }
    // 오른쪽 스택에서 하나씩 출력 (최종 결과)
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

    return 0;
}
