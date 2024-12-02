//백준 11724 연결요소 개수 BFS로 구현해보기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();    
        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(!visited[y]){
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

int main(){
    int N,M,a,b,cnt=0;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b; //시작점과 끝점 입력
        //벡터안에 값을 주고받음 연결 입력
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }
    for(int i=1; i<=N; i++){
        if(visited[i] == 0){
        BFS(i);
        cnt++;
    }
    }
    cout << cnt << "\n";
}