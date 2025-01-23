//백준 2589 보물섬
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int vis[51][51]; //방문기록을 설정
char grid[51][51]; //보물지도 입력
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mx = 0;
int N,M;
queue<pair<int,int>> Q;

void BFS(int i,int j){
    while(!Q.empty()) Q.pop();
    memset(vis,-1,sizeof(vis)); // vis 초기화
    vis[i][j] = 0;
    Q.push({i,j});
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int k=0; k<4; k++){
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(grid[nx][ny] == 'W' || vis[nx][ny] != -1) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
        mx = max(mx,vis[cur.first][cur.second]);
    }
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
        }
    }//보물지도 입력.
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] == 'L'){
                BFS(i,j);
            }
        }
    }
    cout << mx << endl;
}