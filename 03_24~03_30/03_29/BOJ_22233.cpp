//백준 22233 가희와 키워드
#include <iostream>
#include <unordered_set>
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
    unordered_set<string> keywords;
    for (int i = 0; i < N; i++) {  // 키워드 입력 저장
        string str;
        cin >> str;
        keywords.insert(str);
    }
    for (int i = 0; i < M; i++) { // 블로그 글 입력 처리
        string str;
        cin >> str;

        // ','를 기준으로 키워드 분리 및 삭제
        size_t pos = 0;
        while ((pos = str.find(',')) != string::npos) {
            //string::npos는 -1 값을 가지는 상수로 find() 함수 수행 시에 찾는 문자열이 없을 때 반환
            string word = str.substr(0, pos); // ',' 앞의 키워드 추출
            keywords.erase(word); // 키워드 제거
            str.erase(0, pos + 1);
        } //while문이 끝나면 마지막 키워드가 남게되기에 제거해줌
        keywords.erase(str); // 마지막 키워드 제거

        cout << keywords.size() << '\n'; // 남은 키워드 개수 출력
    }

    return 0;
}