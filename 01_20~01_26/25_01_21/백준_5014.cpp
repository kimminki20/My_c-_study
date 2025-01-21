//백준 5014 스타트링크
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int result[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int Floor,current_floor,Destinaion,Up,Down;
    cin >> Floor >> current_floor >> Destinaion >> Up >> Down;
    if (current_floor == Destinaion) {
        cout << 0; // 시작 위치가 목표 위치인 경우
        return 0;
    }
    fill(result,result+1000001,-1); //초기화
    result[current_floor] = 0;
    queue<int> Q;
    Q.push(current_floor);
    while(!Q.empty()){
        int cur = Q.front(); 
        Q.pop();
        for(int next : {cur+Up,cur-Down}){
            if(next <= 0 || next > Floor ) continue;
            if(result[next] != -1) continue;
            result[next] = result[cur] + 1;
            Q.push(next);
            if(next == Destinaion){
                cout << result[next];
                return 0;
            }
        }
    }
    cout << "use the stairs";
    return 0;
}