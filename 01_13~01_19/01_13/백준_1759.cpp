#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C; // L은 암호 길이, C는 입력받은 알파벳 개수
vector<char> input; // 입력받은 알파벳
vector<char> password; // 현재 조합된 암호
string vowels = "aeiou"; // 모음 리스트

bool isVowel(char c) {// 모음인지 체크하는 함수
    return vowels.find(c) != string::npos;
}

void makePassword(int idx, int cnt) {// 암호 구성 함수
    if (cnt == L) { // 암호의 길이가 L에 도달했을 때
        int vowelCount = 0, consonantCount = 0;
        for (char c : password) {
            if (isVowel(c)) vowelCount++;
            else consonantCount++;
        }
        if (vowelCount >= 1 && consonantCount >= 2) { // 조건을 만족하면 출력
            for (char c : password) cout << c;
            cout << "\n";
        }
        return;
    }
    for (int i = idx; i < C; i++) {
        password.push_back(input[i]); // 알파벳 추가
        makePassword(i + 1, cnt + 1); // 재귀 호출로 다음 알파벳 선택
        password.pop_back(); // 백트래킹
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> C; //암호의 길이, 주어진 알파벳의 개수
    input.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end()); // 오름차순 정렬
    makePassword(0, 0); // 암호 생성 시작
    return 0;
}
