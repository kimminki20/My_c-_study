// 백준 1283 단축키 지정
// https://www.acmicpc.net/problem/1283

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<char, bool> alpha;  // 알파벳 사용 여부 저장
vector<string> st;                // 입력된 옵션들 저장
int N;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void test(const vector<string>& st) { // 단축키 설정 로직
    for (string line : st) {
        vector<string> words;
        string word;
        // 단어 단위로 분리
        for (int i = 0; i <= line.size(); ++i) {
            if (i == line.size() || line[i] == ' ') {
                if (!word.empty()) words.push_back(word);
                word.clear();
            } else {
                word += line[i];
            }
        }
        /*
        #include <sstream> 필요
        istringstream iss(line);  // 한 줄을 스트림에 넣기
        vector<string> words;
        string word;
        // 공백 단위로 단어 분리
        while (iss >> word) {
            words.push_back(word);
        }
        */
        // 1단계: 각 단어의 첫 글자부터 확인
        bool shortcutAssigned = false;
        for (int i = 0; i < words.size(); ++i) {
            char ch = tolower(words[i][0]);
            if (!alpha[ch]) {
                alpha[ch] = true;
                int idx = 0; // 전체 문장 기준에서 단축키 위치 계산
                for (int j = 0; j < i; ++j) {
                    idx += words[j].size() + 1;  // 이전 단어 + 공백
                }

                line.insert(idx, "[");
                line.insert(idx + 2, "]");
                shortcutAssigned = true;
                break;
            }
        }

        // 2단계: 전체 문자열에서 단축키 설정 시도
        if (!shortcutAssigned) {
            for (int i = 0; i < line.size(); ++i) {
                if (line[i] == ' ') continue;
                char ch = tolower(line[i]);
                if (!alpha[ch]) {
                    alpha[ch] = true;
                    line.insert(i, "[");
                    line.insert(i + 2, "]");
                    break;
                }
            }
        }

        cout << line << '\n';
    }
}

int main() {
    init();
    cin >> N;        // 옵션 개수
    cin.ignore();    // 개행 제거

    for (int i = 0; i < N; ++i) {
        string input;
        getline(cin, input);
        st.push_back(input);
    }

    // 알파벳 사용 여부 초기화
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        alpha[ch] = false;
    }

    test(st);
    return 0;
}
