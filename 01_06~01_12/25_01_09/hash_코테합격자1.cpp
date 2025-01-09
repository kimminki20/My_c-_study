//코테 합격자되기 hash부분 문제
/*참여자가 N명, 완주자 N-1명
  참여자 중에서 완주하지못한 사람 1명 찾는 코드
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant,vector<string> completion){
    unordered_map<string,int> ph; //participant를 나타낼 해시 테이블
    //동명이인이 존재할 수 있기에 뒤에 int형을 두어서 명수를 확인
    for(int i=0; i<participant.size(); i++){
        ph[participant[i]]++; //각 참가자를 해시 테이블에 추가(키는 이름,값은 이름의 명수)
    }
    for(int i=0; i<completion.size(); i++){
        ph[completion[i]]--; //참가자 정보가 저장된 해시 테이블에서 완주한 선수들 제외
        if(ph[completion] == 0){// 특정 이름이 0명이면 삭제
            ph.erase(ph.find(completion[i]));
        }
    }
    return ph.begin() ->  first; //저 과정을 거치면 ph.begin()의 first. 즉, 이름만 남음.
}

int main(){
    ios_base::sync_with_stdio(false);
    cin::tie(0);
    int N;
    cin >> N;
    vector<string> participant;
    vector<string> completion;
    for(int i=0; i<N; i++){
        string st1;
        cin >> st1;
        participant.push_back(st1);
    }
    for(int i=0; i<N-1; i++){
        string st2;
        cin >> st2;
        completion.push_back(st2);
    }
    cout << solution(participant,completion) <<endl;

}
