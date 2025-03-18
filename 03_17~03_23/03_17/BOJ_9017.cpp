//백준 9017 크로스 컨트리
#include <iostream> 
#include <vector>   
#include <map>     
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T; 
    cin >> T; // 테스트 케이스의 수 입력

    for(int t = 0; t < T; t++){ // 각 테스트 케이스에 대해 반복
        int N; cin >> N;        // 레이스에 참가한 선수의 수 입력
        
        vector<int> race;       // 선수들의 팀 번호를 저장하는 벡터
        map<int, int> maps;     // 각 팀 번호별 선수 수를 저장하는 맵

        // N명의 선수에 대해 팀 번호 입력받기
        for(int i = 0; i < N; i++){
            int n; 
            cin >> n;    // 각 선수의 팀 번호 입력
            maps[n]++;          // 해당 팀 번호의 선수 수 증가
            race.push_back(n);  // 팀 번호를 race 벡터에 추가
        }

        vector<int> scores[201]; // 팀별 점수를 저장하는 벡터 배열 (팀 번호 1~200까지 가능)
        int idx = 1;             // 점수 부여를 위한 순위 인덱스
        for(int i = 0; i < N; i++){
            // 팀원이 6명인 경우에만 점수 부여
            if(maps[race[i]] == 6) {
                scores[race[i]].push_back(idx); // 해당 팀의 순위 점수 추가
                idx++;                           // 다음 순위로 증가
            }
        }

        int winner = -1;         // 우승 팀 번호 초기화
        int winScore = 1231312;  // 최소 점수를 찾기 위한 초기 큰 값
        int five = -1;           // 5번째 주자의 점수 초기화

        // 팀 번호 1부터 200까지 확인
        for(int i = 1; i < 201; i++){
            int tmp = 0;         // 현재 팀의 상위 4명 점수 합계

            // 팀원이 정확히 6명인 경우만 계산
            if(scores[i].size() == 6){
                // 상위 4명의 점수 합산
                for(int j = 0; j < 4; j++) tmp += scores[i][j];

                // 현재 팀의 점수가 더 작으면 우승 후보 갱신
                if(tmp < winScore) {
                    winScore = tmp;      // 최소 점수 갱신
                    winner = i;          // 우승 팀 번호 갱신
                    five = scores[i][4]; // 5번째 주자의 점수 저장
                }

                // 점수가 같을 경우, 5번째 주자의 점수가 더 작은 팀이 우승
                if(tmp == winScore && five > scores[i][4]){
                    winner = i;          // 우승 팀 번호 갱신
                    five = scores[i][4]; // 5번째 주자의 점수 갱신
                }
            }
        }

        cout << winner << '\n'; // 우승 팀 번호 출력
    }
}