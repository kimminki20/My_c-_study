//백준 15649 N과 M
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int N,M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void dfs(int cnt){
    if(cnt == M){ //수열이 완성된것
        for(int i=0; i<M; i++){
            cout << arr[i] << ' ';
        }
            cout << '\n';
            return;
        
    }
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i] = true; //현재 숫자 선택
            arr[cnt] = i; //선택한 숫자 저장
            dfs(cnt+1); //다음단계로 진행
            visited[i] = false; //선택해제(백트래킹)
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M; // 1~N 자연수 중에서 중복잆어 M개를 고른 수열 출력
    dfs(0);
}