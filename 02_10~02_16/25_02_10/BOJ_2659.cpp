#include <iostream>
#include <set>
using namespace std;

int get_clock_number(int arr[]) {// 네 자리 숫자의 최소 시계수를 찾는 함수
    int min_val = 9999;
    for (int i = 0; i < 4; i++) {
        int num = arr[i] * 1000 + arr[(i + 1) % 4] * 100 + arr[(i + 2) % 4] * 10 + arr[(i + 3) % 4];
        if (num < min_val) min_val = num;
    }
    return min_val;
}

bool contains_zero(int num) {// 네 자리 숫자 중 0이 포함되었는지 확인하는 함수
    while (num > 0) {
        if (num % 10 == 0) return true;
        num /= 10;
    }
    return false;
}

int main() {
    int arr[4];
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];  // 네 개의 숫자 입력 받기
    }
    int clock_number = get_clock_number(arr);// 현재 입력값의 최소 시계수 구하기

    // 1111부터 clock_number까지 모든 숫자의 최소 시계수를 set에 저장 (0이 포함된 숫자는 제외)
    set<int> clock_numbers;
    for (int num = 1111; num <= clock_number; num++) {
        if (contains_zero(num)) continue; // 0이 포함된 경우 무시
        int digits[4] = {num / 1000, (num / 100) % 10, (num / 10) % 10, num % 10};
        int min_clock = get_clock_number(digits); //숫자의 시계수 변환
        clock_numbers.insert(min_clock); // 시계수를 set에 저장 (중복 자동 제거)
    }

    // 몇 번째인지 출력
    cout << clock_numbers.size() << endl;

    return 0;
}
