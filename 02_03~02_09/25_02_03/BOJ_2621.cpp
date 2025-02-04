//백준 2621 카드게임
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<pair<char,int>> v(5);
    for(int i=0; i<5; i++){
        cin >> v[i].first >> v[i].second;
    }//값 입력하기
    int R=0,B=0,Y=0,G=0;
    for(int i=0; i<5; i++){
        if(v[i].first == 'R') R++;
        if(v[i].first == 'B') B++;
        if(v[i].first == 'Y') Y++;
        if(v[i].first == 'G') G++;
    } //색상이 같은 경우만 판단
    
}