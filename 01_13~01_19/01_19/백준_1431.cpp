#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int sumOfDigits(const string& s) {// 숫자의 합을 계산하는 함수
    int sum = 0;
    for (char ch : s) {
        if (isdigit(ch)) {
            sum += (ch - '0');
        }
    }
    return sum;
}
bool compare(const string& a, const string& b) {
    if (a.length() != b.length())    // 1. 길이가 짧은 순
        return a.length() < b.length(); //a가 b보다 먼저 정렬
    // 2. 숫자의 합이 작은 순
    int sumA = sumOfDigits(a);
    int sumB = sumOfDigits(b);
    if (sumA != sumB)
        return sumA < sumB; 
    // 3. 사전순
    return a < b;
}
int main() {
    int N;
    cin >> N; // 기타의 개수 N개
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end(), compare); // 정렬( Nlog(N))
    for (const string& st : S) {
        cout << st << '\n'; // 결과 출력
    }

    return 0;
}
