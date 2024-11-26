#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int MAX = 501;
int map[MAX][MAX] = {0,};
int dy[] = {0,0,-1,1}; //행 방향 이동 0,0,위,아래
int dx[] = {1,-1,0,0}; //열 방향 이동 좌,우,0,0
bool visited[MAX][MAX] = {0,};
queue<pair<int,int>> q;
vector<int> v;
int s =1;

void BFS(int y,int x){
    visited[y][x] = true;
    q.push(make_pair(y,x)); //q에 값 넣기
    
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){ //4방향 탐색
            int ny = y + dy[i]; //새로운 y좌표
            int nx = x + dx[i]; //새로운 x좌표
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) 
                continue; //-1이 있기에 값이 0보다 작으면 위로 벗어나거나 왼쪽으로 벗어난 것
                //1이 있기에 입력한 좌표 값보다 값을 벗어난 경우
            if(map[ny][nx]== 1 && visited[ny][nx] == 0){
                //새 좌표 (nx,ny)가 1이고 아직 방문하지 않은 경우
                visited[ny][nx] = true; //방문처리
                s++; //영역 사이즈 증가
                q.push(make_pair(ny,nx)); //큐에 새로운 좌표 넣기
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    int cnt = 0; //영역의 개수
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                BFS(i,j);
                v.push_back(s);
                cnt++;
                s = 1;
            }
        }
    } 
    sort(v.rbegin(),v.rend());
    cout << cnt << endl;
    if( cnt == 0)
        cout << 0 << endl;
    else {
        cout << v[0] << endl;
    }
    return 0;
}