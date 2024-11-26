//백준 2178 미로 찾기 문제 
#include <iostream>
#include <queue>
#include <string>
#define MAX 101

using namespace std;

int N, M;                       // 미로 크기
int maze[MAX][MAX];             // 미로 표현용 2차원 배열
int visited[MAX][MAX];          // 방문 기록용 2차원 배열
int dist[MAX][MAX];             // 이동칸 기록용 2차원 배열

int dx[4] = {-1, 1, 0, 0};   // 상화좌우 x축 방향
int dy[4] = {0, 0, -1, 1};   // 상화좌우 y축 방향

queue<pair<int,int> > q;        // 탐색 좌표 저장용 queue

// 미로 경로 탐색
void BFS(int y, int x){
    visited[y][x] = 1; //방문한 곳은 1로
    q.push(make_pair(y,x)); // y,x값을 넣어줌
    dist[y][x]++; //시작 좌표부터 이동한 칸을 1로 지정
    while (!q.empty()) //비어있을떄 까지 반복 비어 있으면 1을 반환함
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){ //상하좌우를 확인하면서 방문거리수를 넣어줌
            int ny = y + dy[i];
            int nx = x + dx[i];
            if((0<= nx && nx < M) && (0<= ny && ny < N) && !visited[ny][nx] && maze[ny][nx] == 1){
                visited[ny][nx] = 1;
                q.push(make_pair(ny,nx));
                dist[ny][nx] = dist[y][x] +1;
            }
        }
    }
    
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string a;
        cin >> a;
        for(int j=0; j<M; j++){
            maze[i][j] = a[j] - '0';
        }
    }
    BFS(0,0);
    cout << dist[N-1][M-1];
}