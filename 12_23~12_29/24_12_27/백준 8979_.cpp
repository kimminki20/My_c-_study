#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Country { //구조체로 선언
    int id;        // 국가 번호
    int gold;      // 금메달 수
    int silver;    // 은메달 수
    int bronze;    // 동메달 수

    // 메달 점수를 비교하는 함수
    bool operator<(const Country& other) const {
        if (gold != other.gold) return gold > other.gold;          // 금메달 수 내림차순
        if (silver != other.silver) return silver > other.silver; // 은메달 수 내림차순
        return bronze > other.bronze;                             // 동메달 수 내림차순
    }
};

int main() {
    int N, K; // 국가 수와 등수를 알고 싶은 국가 번호
    cin >> N >> K;
    vector<Country> countries(N);
    for (int i = 0; i < N; i++) {
        cin >> countries[i].id >> countries[i].gold >> countries[i].silver >> countries[i].bronze;
    }
    // 메달 기준으로 정렬
    sort(countries.begin(), countries.end());
    // K번 국가의 등수를 계산
    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (i > 0 && !(countries[i] < countries[i - 1]) && !(countries[i - 1] < countries[i])) {
            // 현재 국가와 이전 국가가 동점인 경우
        } else {
            rank = i + 1; // 동점이 아니면 새로운 순위
        }
        if (countries[i].id == K) { // K번 국가를 찾으면 순위 출력
            cout << rank << endl;
            break;
        }
    }
    return 0;
}
 //100점짜리 코드.