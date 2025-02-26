#include <iostream>
#include <vector>
using namespace std;

int main() {
    int P;
    cin >> P;
    vector<int> result; // 결과 저장 벡터

    for (int t = 1; t <= P; t++) {
        vector<int> v;
        int num;
        cin >> num;
        int total_moves = 0; // 총 이동 횟수

        for (int i = 0; i < 20; i++) {
            int height;
            cin >> height;

            int count = 0; // 현재 학생이 들어갈 때 이동 횟수
            for (int j = 0; j < v.size(); j++) {
                if (height < v[j]) count++;
            }

            v.push_back(height); // 새로운 키 삽입
            total_moves += count; // 이동 횟수 누적
        }

        result.push_back(total_moves); // 결과 저장
    }

    // 결과 출력
    for (int i = 0; i < result.size(); i++) {
        cout << i + 1 << ' ' << result[i] << '\n';
    }

    return 0;
}
