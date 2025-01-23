//백준 6593 상범 빌딩
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <typle>
using namespace std;

int dx[6] = {1,-1,0,0,0,0}; //상하
int dy[6] = {0,0,1,-1,0,0}; //좌우
int dz[6] = {0,0,0,0,1,-1}; //위아래
int building[30][30][30]; //빌딩기록
int vis[30][30][30]; //방문기록
int floor,row,col;
queue<tuple<int,int,int>> Q;

void BFS(int z,int x, int y,int e_z,int e_x, int e_y){ //시작지점을 인자로 보내주고 BFS탐색
    memset(vis,0,sizeof(vis));
    while (!Q.empty()) Q.pop(); // 큐 초기화
    Q.push({x,y,z});
    vis[x][y][z] = 1;
    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front();
        Q.pop();
        for(int dir=0; dir<6; dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if(nx < 0 || nx >= row || ny < 0 || ny >= col || nz < 0 || nz >= floor) 
                continue;
            if(building[nx][ny][nz] != 1 || vis[nx][ny][nz])
                continue;
            vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push({nx,ny,nz});
            if(nx == e_x && ny == e_y && nz == e_z){
                cout << "Escaped in " << vis[nx][ny][nz] -1 << " minute(s)";
                return;
            }
        }
    }
    cout << "Trapped!" << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char s;
    int s_x,s_y,s_z; //시작점
    int e_x,e_y,e_z; //탈출지점
    while(cin >> floor >> row >> col){
         if (floor == 0 && row == 0 && col == 0) break; // 0 0 0일 때 종료
    for (int i = 0; i < floor; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                cin >> s;
                if (s == '.') {
                    building[i][j][k] = 1; // 이동 가능
                } else if (s == '#') {
                    building[i][j][k] = 0; // 이동 불가능
                } else if (s == 'S') { // 시작 위치
                    s_x = j;
                    s_y = k;
                    s_z = i;
                } else { // 탈출 위치
                    e_x = j;
                    e_y = k;
                    e_z = i;
                    }
                }
            }
        }
        BFS(s_z,s_x,s_y,e_z,e_x,e_y); 
    }
    return 0;
}


// 왜 안풀리는거냐고오오오오ㅗ옹!!!! 16%에서 계속 틀림

