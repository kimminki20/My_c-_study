//백준 8979 올림픽
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int,int>> v;
    int N,K; //입력할 국가 수, 등수 알고싶은 국가 번호
    cin >> N >> K;
    for(int i=0; i<N; i++){
    int a,b,c,d; //a는 번호, b는 금메달 c는 은메달, d는 동메달
    cin >> a >> b >> c >> d;
    /*v[i].first = a;
    v[i].second = (3*b+c*2+d*1); 이거보다는 벡터를 썻기에 아래처럼 쓰기*/
    v.push_back({a, 3 * b + 2 * c + d});
    } //입력받은 값들을 vector에 저장 first는 나라, second는 메달수
    sort(v.begin(), v.end(),[](const pair<int,int>& a, const pair<int,int>&b){
        return a.second > b.second; //내림 차순 정렬
    });
     // 등수 계산
    int rank = 1; // 초기 순위
    for (int i = 0; i < N; i++) {
        if (i > 0 && v[i].second < v[i - 1].second) {
            rank = i + 1; // 점수가 낮아지면 순위 업데이트
        }
        if (v[i].first == K) { // K번 국가를 찾으면 출력
            cout << rank << endl;
            break;
        }
    }
    return 0;
}
//40점짜리 코드