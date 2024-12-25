//백준 1963 소수 경로
/* 고민해도 답이 안나오던 문제 결국 답보고 어떻게 푸는지 확인함.
    에라토스테네스의 체라는 개념 사용 + BFS로 해결
    에라토스테네스의 체: 마치 체처럼 걸러낸다고 하여 이름 붙인 이 알고리즘은, 
    2 이상 n 이하의 정수 x가 소수인지 아닌지 효율적으로 판단할 수 있도록 추가적인 배열을 만드는 전처리 알고리즘입니다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring> 
#include <tuple> //tie()
using namespace std; 
int n;
bool check[10001];
bool visited[10001]; 
string s1, s2; 

void init() { //에라토스테네스의 체 알고리즘 사용
    for (int i = 2; i < 10000; i++) {		
        if (check[i] == false) { // i가 소수라면
            for (int j = i * 2; j < 10000; j += i) { 
                check[j] = true; // i의 배수를 모두 소수가 아니라고 표시
            }
        }
    }
}

void dfs() {
    queue <pair<string, int>> q;
    visited[stoi(s1)] = true; // 시작 숫자를 방문처리 문자 -> 숫자
    q.push({ s1, 0 }); // 시작 숫자와 현재 변환 횟수(0)를 큐에 추가
    while (!q.empty()) {
        string s; 
        int cnt; 
        tie(s, cnt) = q.front(); // 큐에서 현재 숫자와 변환 횟수를 가져옴
        q.pop();
        
        if (s == s2) { // 목표 숫자에 도달하면 변환 횟수를 출력하고 종료
            cout << cnt << endl; 
            return; 
        }		 
        
        for (int i = 0; i < 4; i++) { // 숫자의 각 자리수에 대해
            for (int j = 0; j <= 9; j++) { // 0부터 9까지 시도
                string ss = s; 
                ss[i] = j + '0'; // i번째 자리를 j로 변경
                int next = stoi(ss); // 변경된 숫자를 정수로 변환
                
                // 조건 체크
                if (check[next] == true) continue; // 소수가 아니면 건너뜀
                if (visited[next] == true) continue; // 이미 방문한 숫자면 건너뜀
                if (next < 1000) continue; // 네 자리 숫자가 아니면 건너뜀
                
                visited[next] = true; // 방문 처리
                q.push({ss, cnt + 1}); // 큐에 새로운 숫자와 변환 횟수 추가
            }
        }
    }	
    cout << "Impossible" << endl; // 목표 숫자에 도달하지 못한 경우
}

int main() {
    cin >> n; // 테스트 케이스 개수 입력
    init(); // 소수 계산
    while (n--) {
        cin >> s1 >> s2; // 시작 숫자와 목표 숫자 입력
        dfs(); // BFS 수행
        memset(visited, false, sizeof(visited)); // 방문 배열 초기화
    }
}