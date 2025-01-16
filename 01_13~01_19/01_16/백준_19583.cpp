//백준 19583 싸이버개강총회
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string,int> attend;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S,E,Q; //개강총회 시작 시간 S,끝낸 시간 E, 개강총회 스트리밍 끝난 시간 Q
    string time,name;
    cin >> S >> E >> Q; //각각의 시간을 입력받음
    int answer = 0;
    while(cin >> time >> name){ //이런식으로 입력을 받고 ctrl+D눌러서 종료.
        if(time <= S){ //시간 전 or 시간에 정확히 채팅을 친 경우 출석부에 등록
            attend[name] = 1;
        }
        else if(time >= E && time <= Q){ //시간 안에 채팅 친 경우 E <= time <= Q 사이
            if(attend[name] == 1){
                attend[name] = 2;
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}