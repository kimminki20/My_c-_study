//백준 7785 회사에 있는 사람 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N; //로그에 기록된 출입 기록 입력 횟수
    string s1, s2;
    vector<pair<string,int>> Log;
    for(int i=0; i<N; i++){
        cin >> s1 >> s2; //s1은 이름, s2는 enter||leave
        if(s2 == "enter"){
            Log.push_back({s1,1});
        }
        else{
            for(int i=0; i<Log.size(); i++){
            if(s1 == Log[i].first)
                Log[i].second = 0;
                break;
          }
        }
    }
    // 사전 역순으로 정렬
    sort(Log.begin(), Log.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first > b.first;
    });
    for(int i=0; i<Log.size(); i++){
        if(Log[i].second == 1)
         cout << Log[i].first << '\n';
        }
    } //For문을 너무 많이 사용해서 출력 초과 발생.