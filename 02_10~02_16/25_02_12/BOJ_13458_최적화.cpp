#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    long long total_supervisors = 0;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int B, C;
    cin >> B >> C; // B: 총감독관 감시 가능 인원, C: 부감독관 감시 가능 인원

    for (int i = 0; i < N; i++) {
        int students = v[i]; 
        total_supervisors++; // 총감독관은 반드시 한 명 필요
        students -= B; // 총감독관이 감시한 만큼 제외

        if (students > 0) { // 남은 학생이 있을 경우 부감독관 배치
            total_supervisors += (students + C - 1) / C; // 올림 나눗셈 처리
        }
    }

    cout << total_supervisors << '\n'; // endl 대신 '\n'을 써서 출력 최적화
    return 0;
}
