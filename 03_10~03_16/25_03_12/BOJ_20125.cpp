//백준 20125 쿠키의 신체 측정
//첫줄에는 심장이 위치한 행 x , 열 y를 출력
//각각 왼쪽 팔, 오른쪽 팔, 허리, 왼쪽 다리, 오른쪽 다리의 길이를 공백으로 구분해서 출력
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> v; // 전역 변수로 변경
pair<int, int> waist, heart; // 각각의 시작점 저장

int RightArm(int x, int y) {
    int length = 0;
    while (y + 1 < N && v[x][y + 1] == '*') {
        length++;
        y++;
    }
    return length;
}

int LeftArm(int x, int y) {
    int length = 0;
    while (y - 1 >= 0 && v[x][y - 1] == '*') {
        length++;
        y--;
    }
    return length;
}

int Waist(int x, int y) {
    int length = 0;
    while (x + 1 < N && v[x + 1][y] == '*') {
        length++;
        x++;
    }
    waist = make_pair(x, y);
    return length;
}

int LegLength(int x, int y) {
    int length = 0;
    while (x < N && v[x][y] == '*') {
        length++;
        x++;
    }
    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    v.assign(N, vector<char>(N)); // 2차원 배열 동적 할당

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j]; // 값 입력
        }
    }

    // 심장 위치 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] == '*') {
                heart = make_pair(i + 1, j); // 심장 위치 저장
                cout << heart.first + 1 << ' ' << heart.second + 1 << '\n'; // 1-based index로 출력
                break;
            }
        }
        if (heart.first != 0) break; // 심장 찾으면 종료
    }

    vector<int> result;
    int x = heart.first, y = heart.second;
    result.push_back(LeftArm(x, y));
    result.push_back(RightArm(x, y));
    result.push_back(Waist(x, y));

    x = waist.first, y = waist.second;
    result.push_back(LegLength(x + 1, y - 1)); // 왼다리
    result.push_back(LegLength(x + 1, y + 1)); // 오른다리

    for (auto data : result) {
        cout << data << ' ';
    }

    return 0;
}