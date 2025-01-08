//백준 1351번 무한수열
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, P, Q;
    cin >> N >> P >> Q; // N: 수열 크기, P와 Q는 수열 계산에 사용
    if (N == 0) { // N = 0인 경우 예외 처리
        cout << 1 << endl;
        return 0;
    }
    vector<int> sequence(N + 1); // N + 1 크기로 벡터 초기화
    sequence[0] = 1; // 수열의 0번째는 1로 초기화

    for (int i = 1; i <= N; i++) {
        int num1 = (i / P < i) ? sequence[i / P] : 0; // 벡터 범위 내인지 확인
        int num2 = (i / Q < i) ? sequence[i / Q] : 0; // 벡터 범위 내인지 확인
        sequence[i] = num1 + num2; // 수열 계산
    }
    cout << sequence[N] << endl; // N번째 값 출력
    return 0;
} //너무 큰 값을 저장 할 수 없음.
//int -> long long으로 바꿔서 제출 --> 메모리 초과