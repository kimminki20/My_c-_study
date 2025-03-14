//백준 25757 임스와 함께하는 미니게임
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int N,Full; // 임스와 게임을 함꼐하기 위해 신청한 횟수
    string Game; //게임의 종류
    cin >> N >> Game;
    if(Game == "Y"){
        Full = 1;
    }
    else if(Game == "F"){
        Full = 2;
    }
    else{
        Full = 3;
    }
    set <string> member;
    for(int i=0; i<N; i++){
        string name;
        cin >> name;
        member.insert(name);
    } //중복을 제외하고 오름차순으로 정렬
    vector <string> ReMember(member.begin(),member.end()); //변환
    int result = 0; //게임이 가능한 수(결과값)
    size_t count = 0;
    for(size_t i=0; i<ReMember.size(); i++){
        count++;
        if(count == Full){
            result++;
            count = 0;
        }
    }
    cout << result << endl;
}