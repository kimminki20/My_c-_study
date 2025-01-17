//백준 15650 N과 M(2) //오름차순만 골라야함
#include <iostream>
#define MAX 9
using namespace std;
int N,M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void solve(int count,int start){
    if(count == M){
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=start; i<=N; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[count] = i;
            solve(count+1,i+1); //이거로 오름차순 가능
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    solve(0,1); //시작값을 1부터 선택해야 큰 값만 선택가능
}