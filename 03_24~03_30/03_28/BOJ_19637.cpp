//백준 19637 IF문 좀 대신 써줘
#include <iostream>
#include <vector>
using namespace std;

void init() { 
    ios_base::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int N,M;
    long score = 0;
    cin >> N >> M; // N은 칭호의 수, M은 칭호 출력 캐릭터 수
    vector<pair<string,int>> input(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i].first >> input[i].second;
    }//칭호 입력
    for(int i=0; i<M; i++){
        cin >> score;
        for(int j=0; j<N; j++){
            if(input[j].second >= score){
                cout << input[j].first << '\n';
                break;
            }
        }
    }
    return 0;
} //이렇게 하면 시간 초과 발생

//이진탐색 사용해서 푸는게 어떨까해서 구현
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    vector<pair<string, int>> titles(N);
    for (int i = 0; i < N; i++) {
        cin >> titles[i].first >> titles[i].second;
    }
    while (M--) {
        int score;
        cin >> score;
        // 이진 탐색 (lower_bound 사용)
        int left = 0, right = N - 1, result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (titles[mid].second >= score) { 
                result = mid; 
                right = mid - 1; // 더 작은 범위 탐색
            } else {
                left = mid + 1;
            }
        }
        cout << titles[result].first << '\n'; // 출력
    }

    return 0;
}
