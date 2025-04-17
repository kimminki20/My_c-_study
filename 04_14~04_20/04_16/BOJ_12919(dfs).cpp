//백준 12919 A와 B 2
//https://www.acmicpc.net/problem/12919
//입력받은 string S,T에서 S를 T로 만드는 것이 가능하면 1출력 아니면 0출력 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool possible = false; // S에서 T를 만들 수 있는지 여부
string S, T;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
// 역방향 DFS: T에서 S로 되돌아가는 과정을 재귀적으로 탐색
void dfs(string cur) {
    if (cur == S) {// 기저 조건 1: 목표 문자열 S에 도달
        possible = true;
        return;
    }
    if (cur.size() < S.size() || possible) return;  // 기저 조건 2: 더 이상 줄일 수 없거나 이미 찾았으면 중단
    if (cur.back() == 'A') { // 연산 1: 맨 뒤가 'A'인 경우 → A 제거
        string next = cur;
        next.pop_back(); // 마지막 문자 제거
        dfs(next);       // 다음 상태로 재귀 호출
    }
    if (cur.front() == 'B') {  // 연산 2: 맨 앞이 'B'인 경우 → 문자열 뒤집고 마지막 B 제거
        string next = cur;
        reverse(next.begin(), next.end()); // 문자열 뒤집기
        next.pop_back();                   // 맨 뒤(B) 제거
        dfs(next);                         // 다음 상태로 재귀 호출
    }
}
int main() {
    init();
    cin >> S >> T;// 문자열 S (시작), T (목표) 입력
    dfs(T);// DFS 시작: T에서 S로 되돌아갈 수 있는지 확인
    cout << (possible ? 1 : 0) << '\n'; //true면 1 false면 0 출력
    return 0;
}
