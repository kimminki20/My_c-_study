//백준 9093 단어 뒤집기
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int N;
    cin >> N;
    cin.ignore(); // 버퍼에 남은 개행 문자 제거

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line); // 한 줄 입력

        stringstream ss(line);
        string word;

        while (ss >> word) { // 공백을 기준으로 단어 분리
            reverse(word.begin(), word.end()); // 단어 뒤집기
            cout << word << " ";
        }
        cout << endl; // 한 줄 끝
    }

    return 0;
}

//너무 어렵게 접근한듯함 스택을 사용하면 쉽게 해결이 가능했음.
/*  <sstream> 헤어파일
    공백이나 특정 구분자를 기준으로 문자열을 나눌 때
    예: 한 줄에 입력된 문장을 단어 단위로 분리.

    <예시코드>
    string line = "Hello World from stringstream";
    stringstream ss(line); // 문자열을 스트림으로 생성

    string word;
    while (ss >> word) { // 공백 기준으로 단어 추출
        cout << word << endl;
    }
    
*/