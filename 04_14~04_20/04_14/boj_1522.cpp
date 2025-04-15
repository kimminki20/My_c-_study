//백준 1522 문자열 교환
// https://www.acmicpc.net/problem/1522
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    string st;
    cin >> st;
    int a_count = 0; //a의 갯수 세기 -> 윈도우의 크기 결정
    for(int i=0; i<st.size(); i++){
        if(st[i] == 'a') a_count++;
    } // a의 갯수 세기
    vector<int> result;
    for(int i=0; i<st.size(); i++){
        int count = 0;
        for(int j=0; j<a_count; j++){
            if(st[(i+j)%(st.size())] == 'b') count++;
        }
        result.push_back(count);
    }
    int minVal = *min_element(result.begin(),result.end());
    cout << minVal<< '\n';
    return 0;
}