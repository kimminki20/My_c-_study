#include <iostream>
#include <unordered_set> //set으로 해쉬 사용
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    unordered_set<string> input; // 집합 S를 저장
    for (int i = 0; i < N; i++) {
        string st;
        cin >> st;
        input.insert(st); // 집합 S에 문자열 추가
    }
    int count = 0;
    for (int i = 0; i < M; i++) {
        string st;
        cin >> st;
        if (input.find(st) != input.end()) { // 집합 S에 문자열이 있으면
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
