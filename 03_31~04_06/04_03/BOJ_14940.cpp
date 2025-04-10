//백준 14940 쉬운 최단거리
// https://www.acmicpc.net/problem/14940
//문제 읽어보니 BFS로 풀 수 있는 문제인 것 같다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1001

int dy[4] = {0, 0, -1, 1}; //상하좌우
int dx[4] = {-1, 1, 0, 0}; //상하좌우
int arr[MAX][MAX]; //지도
int dist[MAX][MAX]; //거리
int N, M; //행렬 크기
void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    cin >> N >> M; //행렬 크기 입력
    queue<pair<int, int>> q; //큐 선언
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j]; //지도 입력
            if(arr[i][j] == 2){ //출발점
                q.push({i, j}); //큐에 출발점 추가
                dist[i][j] = 0; //거리 초기화
            }
            else if(arr[i][j] == 1){ //길
                dist[i][j] = -1; //길은 -1로 초기화
            }
        }
    }
    while(!q.empty()){ //큐가 빌 때까지
        int y = q.front().first; //y좌표
        int x = q.front().second; //x좌표
        q.pop(); //큐에서 제거
        for(int i=0; i<4; i++){ //상하좌우 탐색
            int ny = y + dy[i]; //새로운 y좌표
            int nx = x + dx[i]; //새로운 x좌표
            if(ny >= 0 && ny < N && nx >= 0 && nx < M){ //범위 체크
                if(arr[ny][nx] == 1 && dist[ny][nx] == -1){ //길이고 방문하지 않았다면
                    dist[ny][nx] = dist[y][x] + 1; //거리 갱신
                    q.push({ny, nx}); //큐에 추가
                }
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0){ //벽
                cout << 0 << " "; //벽은 0
            }
            else if(arr[i][j] == 1 && dist[i][j] == -1){ //길이고 방문하지 않았다면
                cout << -1 << " "; //도달할 수 없는 길은 -1
            }
            else{
                cout << dist[i][j] << " "; //거리 출력
            }
        }
        cout << "\n"; //줄바꿈
    }
    return 0; //종료
}