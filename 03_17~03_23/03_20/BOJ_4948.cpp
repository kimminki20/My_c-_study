//백준 4948 베르트랑 공준
//에라토스테네스의 체를 사용해서 소수를 판별
#include <iostream>
#include <cmath>
using namespace std;

const int Max = 123456 * 2;
bool arr[Max + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // 소수 배열 초기화
    fill_n(arr, Max + 1, true); //전부 true로 초기화
    arr[0] = arr[1] = false; // 0과 1은 소수가 아님
    // 에라토스테네스의 체 적용
    for (int i = 2; i <= Max; i++) {
        if (!arr[i]) continue; // 이미 체크된 숫자 건너뛰기
        for (int j = 2; i * j <= Max; j++) {
            arr[i * j] = false; // 소수의 배수 지우기
        }
    }
    int num;
    while (true) {
        cin >> num;
        if (num == 0) break; // 0이면 종료

        int count = 0;
        for (int i = num + 1; i <= 2 * num; i++) {
            if (arr[i]) count++;
        }
        cout << count << '\n';
    }
}
