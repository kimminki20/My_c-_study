//백준 1446 지름길
// https://www.acmicpc.net/problem/1446
// 문제 : 고속도로 길이와 일반 도로 길이를 고려하여 최단 거리를 구하는 문제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int N, D;
    cin >> N >> D;
    vector<int> map(D+1, 1e9);
    map[0] = 0;
    vector<pair<int,int>> dist[10001]; //고속도로 길이
    for(int i=0; i<N; i++){
        int start,end,length;
        cin >> start >> end >> length;
        if(length >= end - start) continue; //고속도로 길이가 더 길면 무시
        if(end > D) continue; //고속도로 길이가 더 길면 무시
        dist[start].push_back({end,length});
    }
    for(int i=0; i<=D; i++){ //0부터 D까지의 최단 거리 구하기
        if(i > 0) map[i] = min(map[i], map[i-1] +1); //이전까지의 최단거리,일반 도로를 통해 이동하는 경우 고려
        for(auto [end,length] : dist[i]){
            map[end] = min(map[end], map[i] + length); //현재까지의 최단거리,지름길을 통해 이동하는 경우 고려
        }
    }
    cout << map[D] << '\n'; //최단거리
    return 0;
}