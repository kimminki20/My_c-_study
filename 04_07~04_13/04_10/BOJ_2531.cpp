//백준 2531 회전 초밥
// 문제 링크: https://www.acmicpc.net/problem/2531
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입출력 속도 향상 함수
void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    
    int N, d, k, c;
    cin >> N >> d >> k >> c; 
    // N: 접시 개수, d: 초밥 종류 수, k: 연속해서 먹는 접시 수, c: 쿠폰 번호

    vector<int> sushi(N); // 초밥 벨트 정보 저장
    for(int i = 0; i < N; i++) {
        cin >> sushi[i]; // 각 접시에 놓인 초밥 번호 입력
    }

    vector<int> sushi_count(d + 1, 0); // 각 초밥 번호별 먹은 개수 저장
    int count = 0; // 현재 윈도우 내 서로 다른 초밥 종류 수
    int max_sushi = 0; // 최댓값 초기화
    for(int i = 0; i < k; i++) {// 초기 윈도우(k개) 세팅
        if(sushi_count[sushi[i]] == 0) count++; // 처음 먹는 초밥이면 종류 수 증가
        sushi_count[sushi[i]]++; // 초밥 개수 증가
    }
    if(sushi_count[c] == 0) {// 초기 윈도우에서 쿠폰 고려
        max_sushi = count + 1;
    } else{
        max_sushi = count;
    }
    // 슬라이딩 윈도우: 전체 초밥 벨트를 한 바퀴 돌며 검사
    for(int i = 1; i < N; i++) {
        // 윈도우 앞쪽 초밥 제거
        int remove_sushi = sushi[(i - 1) % N];
        sushi_count[remove_sushi]--;
        if(sushi_count[remove_sushi] == 0) count--; // 종류 하나 빠졌다면 감소

        // 윈도우 뒤쪽 초밥 추가
        int add_sushi = sushi[(i + k - 1) % N];
        if(sushi_count[add_sushi] == 0) count++; // 새 종류라면 증가
        sushi_count[add_sushi]++;

        // 쿠폰 초밥이 현재 윈도우에 없을 경우 추가로 먹을 수 있음
        if(sushi_count[c] == 0) {
            max_sushi = max(max_sushi, count + 1);
        } else {
            max_sushi = max(max_sushi, count);
        }
    }

    cout << max_sushi << '\n'; // 최댓값 출력
}
