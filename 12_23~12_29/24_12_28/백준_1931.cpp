#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> meetings;

    // 입력받기
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        meetings.push_back({end, start}); // 끝나는 시간을 기준으로 정렬하기 위해 (end, start) 순서로 저장
    }

    // 끝나는 시간을 기준으로 정렬 (끝나는 시간이 같으면 시작 시간을 기준으로 정렬)
    sort(meetings.begin(), meetings.end());

    int count = 0;       // 최대 회의 개수
    int lastEndTime = 0; // 마지막 회의가 끝난 시간

    // 회의 선택
    for (const auto& meeting : meetings) {
        if (meeting.second >= lastEndTime) { // 시작 시간이 마지막 끝난 시간 이후일 경우
            lastEndTime = meeting.first;    // 끝나는 시간을 갱신
            count++;                        // 회의 개수 증가
        }
    }

    cout << count; // 최대 회의 개수 출력
    return 0;
}
