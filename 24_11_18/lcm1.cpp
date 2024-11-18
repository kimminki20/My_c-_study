#include <iostream>
using namespace std;

int solution(int x, int y);

int main() {
    int x, y, k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        int result = solution(x, y);
        cout << result << endl;
    }
}

int solution(int x, int y) {
    if ((x < y)||(y<x)) {
        int x1 = x, y1 = y;
        int i = 1, j = 1;
        while (x1 != y1) { // x1과 y1이 같아질 때까지 반복
            if (x1 < y1) {
                x1 = x * i; // x의 배수 갱신
                i++;
            } else {
                y1 = y * j; // y의 배수 갱신
                j++;
            }
        }
        return x1; // 최소공배수 반환
    }
    else {
        return x; // x와 y가 같을 경우 그대로 반환
    }
}