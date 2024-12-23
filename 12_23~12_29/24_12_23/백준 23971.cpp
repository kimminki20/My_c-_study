#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, n, m; // 행, 열, 세로칸, 가로칸
    int count = 0;

    cin >> h >> w >> n >> m; // 값들을 입력

    // 벡터 초기화
    vector<vector<int>> v(h, vector<int>(w, 0));

    for (int i = 0; i < h; i += (n + 1)) { // 세로 방향으로 n+1 간격마다
        for (int j = 0; j < w; j += (m + 1)) { // 가로 방향으로 m+1 간격마다
            if (v[i][j] == 0) {
                count++; // 학생을 배치하고 count 증가
                // 해당 학생이 차지하는 범위를 1로 설정
                for (int k = 0; k <= n && i + k < h; k++) { // 세로 범위
                    for (int s = 0; s <= m && j + s < w; s++) { // 가로 범위
                        v[i + k][j + s] = 1; // 학생이 차지한 위치 표시
                    }
                }
            }
        }
    }
    cout << count << endl; // 결과 출력
    return 0;
}
//메모리 초과 발생 다른 방법 필요 for문 과다 사용.