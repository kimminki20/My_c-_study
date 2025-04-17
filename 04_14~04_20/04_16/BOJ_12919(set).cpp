// 백준 12919 A와 B 2
// https://www.acmicpc.net/problem/12919
// 문자열 S를 시작으로 특정 연산을 반복해서 문자열 T를 만들 수 있는지 확인하는 문제
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    string S, T;
    cin >> S >> T; // 문자열 S와 T 입력
    int num = 0; // 현재 탐색 중인 문자열의 인덱스
    vector<string> st; // BFS처럼 사용할 문자열 리스트 (queue 역할)
    set<string> visited; // 이미 탐색한 문자열을 저장하여 중복 제거
    st.push_back(S);       // 시작 문자열 S를 큐에 넣음
    visited.insert(S);     // 방문 기록에도 추가
    // BFS 탐색 시작
    while(num < st.size()){
        string current = st[num++]; // 현재 문자열 가져오기
        if(current == T){// 목표 문자열 T를 찾았으면 성공
            cout << '1' << '\n';
            return 0;
        }
        if(current.size() < T.size()){// 아직 T보다 문자열이 짧으면 계속 확장 가능
            string addA = current + 'A';// 연산 1: 뒤에 'A' 붙이기
            if(visited.find(addA) == visited.end()){ // 중복 체크
                st.push_back(addA);      // 큐에 추가
                visited.insert(addA);    // 방문 기록
            }
            string addB = current + 'B';// 연산 2: 뒤에 'B' 붙이고 뒤집기
            reverse(addB.begin(), addB.end());
            if(visited.find(addB) == visited.end()){ // 중복 체크
                st.push_back(addB);      // 큐에 추가
                visited.insert(addB);    // 방문 기록
            }
        }
    }
    cout << '0' << '\n'; // 탐색을 다 해도 T를 만들 수 없다면 0출력
    return 0;
} //이렇게 해도 값은 맞게 나오지만 메모리 초과 발생
