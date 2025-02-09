//백준 14503 로봇창소기
#include<iostream>
using namespace std;

int n, m;
int map[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans;
void dfs(int cx, int cy, int cd) {
	if (map[cx][cy] == 0) {
		map[cx][cy] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++) {
		int nd = (cd + 3 - i) % 4; //반시계로 도는거 확인
		int nx = cx + dx[nd];
		int ny = cy + dy[nd];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
			continue;
		} //경계값 확인
		if (map[nx][ny] == 0) {
			dfs(nx, ny, nd); //다음 칸 이동해서 확인
		}
	}    
	int nd = (cd + 2) % 4; //후진
	int nx = cx + dx[nd];
	int ny = cy + dy[nd];

	if (map[nx][ny] == 1) { //후진했는데 벽이면 끝
		cout << ans;
		exit(0);
	}
	dfs(nx, ny, cd);
}


int main(void) {
	cin >> n >> m;

	int r, c, dir;
	cin >> r >> c >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(r, c, dir);

	return 0;
}