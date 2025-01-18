#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 10
using namespace std;

int arr[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};// 0~9까지 선택해야 하므로 전역 변수로 설정
vector<string> sign;// 부등호를 저장할 벡터
int K; // 부등호 개수
vector<int> result;// 결과를 저장할 벡터
vector<bool> visited(MAX, false);// 숫자가 사용되었는지 체크하기 위한 방문 배열
string max_result = "", min_result = ""; // 최대값과 최소값을 저장할 문자열

bool isValid(int a, int b, string op) {// 부등호 조건 검사 함수
    if (op == "<") return a < b;
    if (op == ">") return a > b;
    return false; 
} // a와 b 사이의 부등호 조건(op)이 맞는지 확인

void backtrack_max(int n) { // 최대값을 구하는 백트래킹 함수
    if (n == K + 1) {  // 숫자를 K+1개 선택했다면 결과를 문자열로 만들어 저장
        string current = "";
        for (const int i : result) {
            current += to_string(i);
        }
        max_result = max(max_result, current);
        return;
    }

    for (int i = 9; i >= 0; i--) { // 9부터 0까지 숫자를 탐색하며 조건에 맞는 숫자 선택
        if (!visited[i] && (n == 0 || isValid(result.back(), i, sign[n - 1]))) {   // 숫자가 사용되지 않았고, 부등호 조건에 맞다면
            visited[i] = true;       // 현재 숫자를 방문 처리
            result.push_back(i);    // 결과 벡터에 추가
            backtrack_max(n + 1);   // 다음 단계로 진행
            result.pop_back();      // 선택 해제
            visited[i] = false;     // 방문 처리 해제
        }
    }
}

void backtrack_min(int n) {// 최소값을 구하는 백트래킹 함수
    if (n == K + 1) {   // 숫자를 K+1개 선택했다면 결과를 문자열로 만들어 저장
        string current = "";
        for (const int i : result) {
            current += to_string(i);
        }
        if (min_result.empty() || current < min_result) { // 최소값이 비어 있거나 현재 값이 더 작으면 갱신
            min_result = current;
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {    // 0부터 9까지 숫자를 탐색하며 조건에 맞는 숫자 선택
        if (!visited[i] && (n == 0 || isValid(result.back(), i, sign[n - 1]))) {// 숫자가 사용되지 않았고, 부등호 조건에 맞다면
            visited[i] = true;       // 현재 숫자를 방문 처리
            result.push_back(i);    // 결과 벡터에 추가
            backtrack_min(n + 1);   // 다음 단계로 진행
            result.pop_back();      // 선택 해제
            visited[i] = false;     // 방문 처리 해제
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> K;     // 부등호 입력받을 개수
    for (int i = 0; i < K; i++) {    // 부등호 입력받아 벡터에 저장
        string st;
        cin >> st;
        sign.push_back(st);
    }
    backtrack_max(0);    // 최대값 계산
    result.clear();    // 결과 초기화 및 방문 배열 초기화
    fill(visited.begin(), visited.end(), false); //컨테이너나 배열의 범위 내 모든 원소를 특정 값으로 초기화할 때 사용
    backtrack_min(0);     // 최소값 계산
    cout << max_result << "\n";
    cout << min_result << "\n";
    return 0;
}
