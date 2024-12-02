//백준 11724 연결요소의 개수
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[1001];
int visited[1001];

void DFS(int s){
    visited[s] = 1;
    for(int i=0; i<graph[s].size(); i++){
        int idx = graph[s][i];
        if(visited[idx] == 0)
        {
            DFS(idx);
        }
    }
}
int main(){
    int N,M,a,b,cnt=0;
    cin >> N >> M; //정점의 개수 N, 간선의 개수 M
    for(int i=0; i<M; i++){
        cin >> a >> b; //시작점과 끝점 입력
        //벡터안에 값을 주고받음 연결 입력
        gragh[a].push_back(b);
        gragh[b].push_back(a); 
    }
    for(int i=1; i<=N; i++){
        if(visited[i] == 0){
            cnt++;
            DFS(i);
        }
    }
    cout << cnt <<"\n";
}