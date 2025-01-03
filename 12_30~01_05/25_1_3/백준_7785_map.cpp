#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<string, bool> Log; // 이름과 상태를 저장하는 해시 테이블

    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if (s2 == "enter") {
            Log[s1] = true; // 입장 기록
        } else if (s2 == "leave") {
            Log[s1] = false; // 퇴장 기록
        }
    }

    vector<string> people;
    for (const auto& entry : Log) {
        if (entry.second) { // 회사에 남아 있는 사람만
            people.push_back(entry.first);
        }
    }

    // 사전 역순 정렬
    sort(people.begin(), people.end(), greater<string>());
    //sort(people.begin(),people.end()); 이렇게 하면 순행

    // 결과 출력
    for (const string& person : people) {
        cout << person << '\n';
    }

    return 0;
}
