//백준 1110 더하기 사이클 문제
#include <iostream>
using namespace std;

int main() {
    int N, K, count = 0;
    cin >> N;
    K = N;  // K에 초기 입력값 N을 저장
    do {
        int a, b, c; // 한번 더 나눠서 나온 값
        a = N % 10; // 뒷자리 저장
        b = (N / 10) + a; // 각 자릿수를 더함
        c = b % 10; // 합의 뒷자리만 취함
        N = (a * 10) + c; // 새로 만든 숫자
        count++; // 사이클 카운트 증가
    } while (N != K); // 처음 숫자 K로 돌아올 때까지 반복
    cout << count << endl; // 사이클 길이 출력
}
//do-while을 사용하여 한번은 무조건 동작하게 하는 방법을 택함