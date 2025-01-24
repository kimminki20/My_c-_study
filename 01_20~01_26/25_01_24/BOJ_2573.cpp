#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // memset 사용
using namespace std;

int arr[301][301];
bool vis[301][301];
int row, col;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void melt() {
    int temp[301][301] = {0}; // 빙산 감소를 위한 임시 배열
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > 0) {
                int sea_count = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && arr[nx][ny] == 0) {
                        sea_count++;
                    }
                }
                temp[i][j] = max(0, arr[i][j] - sea_count); // 빙산 감소
            }
        }
    }
    for (int i = 0; i < row; i++) {// 배열 갱신
        for (int j = 0; j < col; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int count_areas() {
    memset(vis, false, sizeof(vis));
    int area = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!vis[i][j] && arr[i][j] > 0) {
                area++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx >= 0 && nx < row && ny >= 0 && ny < col && !vis[nx][ny] && arr[nx][ny] > 0) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    return area;
}

int main() {
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    int year = 0;
    while (true) {
        int area = count_areas();
        if (area >= 2) {
            cout << year << endl;
            break;
        }
        if (area == 0) {
            cout << 0 << endl; // 빙산이 모두 녹은 경우
            break;
        }
        melt();
        year++;
    }
    return 0;
}
