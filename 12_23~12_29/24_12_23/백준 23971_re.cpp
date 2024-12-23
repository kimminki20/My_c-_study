#include <iostream>
using namespace std;

int main() {
    int h, w, n, m; // 행, 열, 세로칸, 가로칸
    cin >> h >> w >> n >> m;

    // (n+1) x (m+1) 크기 간격으로 배치 가능한 학생 수 계산
    // 올림으로 하기 위해서 아래와 같이 수정
    int vertical = (h + n) / (n + 1); // 세로로 배치할 수 있는 학생 수
    int horizontal = (w + m) / (m + 1); // 가로로 배치할 수 있는 학생 수

    cout << vertical * horizontal << endl; // 전체 학생 수 출력
    return 0;
}
