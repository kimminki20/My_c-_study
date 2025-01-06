//백준 1205 등수 구하기
//비오름차순: 점점 감소하는 수열 + 중복이 가능함
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int N,score,P; //N개의 비오름차순 점수,알아볼 점수 score, 점수리스트에 올라가는 갯수 P
    cin >> N >> score >> P; //값들을 입력받음
    vector<pair<int,int>> score_input(N,{0,0});
    int level = 1;
    if(N == 0) cout << 1 << endl;
    else{
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(i==0){
            score_input[i].first = num;
            score_input[i].second = level;
        }
        else{
            if(num == score_input[i-1].first){//이전 값과 일치한다면
                score_input[i].first = num;
                score_input[i].second = score_input[i-1].second; //이전 등수와 일치
                level++;
            }
            else{
                score_input[i].first = num;
                level++;
                score_input[i].second = level;
            }
        }
    } //점수와 등수를 미리 입력해둠
    for(int i=0; i<P; i++){
        if(score_input[i].first > score){
            continue;
        }
        if(score_input[i].first == score){
            if(i == P){ //P의 숫자와 같은 경우 -1 출력
                cout << -1;
            }
            else if(i < P){
                if(score_input[i].second == 0){
                    cout << score_input[i-1].second + 1;
                    break;
                }
            cout << score_input[i].second; // 동일한 점수의 등수 출력
            }
            break;
        }
        if(score_input[i].first < score){
            if(i==0){
                cout << 1;
            }
            if(i>0){
                cout << score_input[i].second;
            }
            break;
            }
        if(i > N && i < P){ //N은 끝났는데 아직 리스트가 남아있는 경우
            cout << score_input[N-1].second + 1;
        }
        }
    }
    return 0;
} //어느 부분이 틀린지 잘 모르겠음 -> 너무 어렵게 생각한듯 함