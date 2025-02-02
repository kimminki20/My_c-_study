#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;  // 테스트 케이스 개수
    while (T--) {
        int N;
        cin >> N;  // 지원자 수
        vector<pair<int, int>> applicants(N);
        for (int i = 0; i < N; i++) {
            cin >> applicants[i].first >> applicants[i].second;//(서류 성적, 면접 성적)
        }
        sort(applicants.begin(), applicants.end());//서류 성적 기준으로 정렬 (오름차순)
        
        int selected = 1;  //면접 성적을 비교하면서 선발,첫 번째 지원자는 무조건 선발
        int min_interview_rank = applicants[0].second;  // 첫 번째 지원자의 면접 성적

        for (int i = 1; i < N; i++) {
            if (applicants[i].second < min_interview_rank) {
                selected++;  // 선발
                min_interview_rank = applicants[i].second;  // 최소 면접 성적 갱신
            }
        }
        cout << selected << '\n';  // 결과 출력
    }

    return 0;
}
