#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char building[30][30][30];
int vis[30][30][30];
int floor, row, col;
queue<tuple<int, int, int>> Q;

void BFS(int z, int x, int y, int e_z, int e_x, int e_y) {
    memset(vis, -1, sizeof(vis));
    while (!Q.empty()) Q.pop();
    Q.push({z, x, y});
    vis[z][x][y] = 0;

    while (!Q.empty()) {
        auto [cur_z, cur_x, cur_y] = Q.front();
        Q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nz = cur_z + dz[dir];
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if (nz < 0 || nz >= floor || nx < 0 || nx >= row || ny < 0 || ny >= col)
                continue;
            if (building[nz][nx][ny] == '#' || vis[nz][nx][ny] >= 0)
                continue;

            vis[nz][nx][ny] = vis[cur_z][cur_x][cur_y] + 1;
            Q.push({nz, nx, ny});

            if (nz == e_z && nx == e_x && ny == e_y) {
                cout << "Escaped in " << vis[nz][nx][ny] << " minute(s)." << '\n';
                return;
            }
        }
    }

    cout << "Trapped!" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char s;
    int s_x, s_y, s_z;
    int e_x, e_y, e_z;

    while (cin >> floor >> row >> col) {
        if (floor == 0 && row == 0 && col == 0) break;

        for (int i = 0; i < floor; i++) {
            for (int j = 0; j < row; j++) {
                for (int k = 0; k < col; k++) {
                    cin >> s;
                    building[i][j][k] = s;
                    if (s == 'S') {
                        s_x = j;
                        s_y = k;
                        s_z = i;
                    } else if (s == 'E') {
                        e_x = j;
                        e_y = k;
                        e_z = i;
                    }
                }
            }
        }

        BFS(s_z, s_x, s_y, e_z, e_x, e_y);
    }

    return 0;
}
