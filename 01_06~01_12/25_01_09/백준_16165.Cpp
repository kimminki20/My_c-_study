//백준 16165 걸그룹 마스터 준석이
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> // for sort and find

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; // 걸그룹 수, 문제 수
    cin >> N >> M;

    map<string, vector<string>> list; 

    // 그룹과 멤버 정보 입력
    for (int i = 0; i < N; i++) {
        string girl_group, member_name;
        cin >> girl_group;
        int members;
        cin >> members;

        for (int j = 0; j < members; j++) {
            cin >> member_name;
            list[girl_group].push_back(member_name);
        }

        // 멤버 목록을 사전순 정렬
        sort(list[girl_group].begin(), list[girl_group].end());
    }

    // 문제 풀이
    for (int i = 0; i < M; i++) {
        string exam;
        cin >> exam;
        int x; // 1: 멤버 -> 그룹, 0: 그룹 -> 멤버
        cin >> x;

        if (x == 0) { // 그룹 이름으로 멤버 출력
            for (const auto& name : list[exam]) {
                cout << name << '\n';
            }
        } else { // 멤버 이름으로 그룹 출력
            for (const auto& [group_name, members] : list) {
                if (find(members.begin(), members.end(), exam) != members.end()) {
                    cout << group_name << '\n';
                    break; // 찾았으면 더 이상 탐색하지 않음
                }
            }
        }
    }

    return 0;
}
