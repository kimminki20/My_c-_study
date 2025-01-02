//백준 2667 단지번호붙이기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int dx[4] = {0,0,-1,1}; //좌우
int dy[4] = {1,-1,0,0}; //상하
int map[26][26]; //입력받을 단지
int visit[26][26]; //방문기록
int N; //맵의 크기

using namespace std;
int BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visit[x][y] = 1;
    int count = 1; //현재 집 포함

    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        int cx = current.first;
        int cy = current.second;
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny] && map[nx][ny]== 1){
                visit[nx][ny] = 1;
                q.push({nx,ny});
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v;
    cin >> N; //맵의 크기 입력받음
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j]; // 사는 집은 '1', 없는 집은 '0'
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visit[i][j] && map[i][j]== 1){
                v.push_back(BFS(i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(int size : v){
        cout << size << '\n';
    } // size는 v의 각 요소를 참조하거나 복사한 값
    return 0;
}