#include <iostream>
#include <string>
using namespace std;

// 소수 판별 함수
int prime(int x) {
    if (x < 2) return 0; // 2보다 작은 수는 소수가 아님
    for (int i = 2; i * i <= x; i++) { // √x까지 검사
        if (x % i == 0) return 0; // 나누어 떨어지면 소수가 아님
    }
    return 1; // 소수
}

// 팰린드롬 판별 함수
int palin(int x) {
    string s = to_string(x); // 숫자를 문자열로 변환
    string reversed_s = string(s.rbegin(), s.rend()); // 문자열 뒤집기
    return s == reversed_s; // 원래 문자열과 비교
}

int main() {
    int K;
    cin >> K; // K 입력

    while (true) {
        if (prime(K) && palin(K)) { // 소수이면서 팰린드롬인지 확인
            cout << K << endl;
            break; // 결과를 출력하고 종료
        }
        K++;
    }

    return 0;
}
