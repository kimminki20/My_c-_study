//백준 9625 BABBA문제
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K;
    cin >> K;

    vector<char> v = {'A'};
    vector<char> buf;

    int A = 0, B = 0; // A와 B를 카운트하기 위한 변수

    while (K--) { // K 횟수만큼 반복
        buf.clear();
        int len = v.size();

        for (int j = 0; j < len; j++) {
            if (v[j] == 'A') {
                buf.push_back('B'); // A는 B로 변환
            } else if (v[j] == 'B') {
                buf.push_back('B'); // B는 B를 유지
                buf.push_back('A'); // B는 추가로 A를 생성
            }
        }

        v = buf;

        // A와 B 개수를 세는 부분
        A = 0;
        B = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 'A') A++;
            else B++;
        }
    }

    cout << A << " " << B << endl; // 최종 결과 출력
    return 0;
}
//답은 맞게 나오나 메모리 초과발생 for문을 너무 많이 써서 그런듯
