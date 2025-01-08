//백준 1351번 무한 수열문제
#include <iostream>
#include <map>

using namespace std;

map<long long, long long> dp; //메모이제이션 map
//이미 계산된 값을 저장하고 재사용하여 중복계산을 줄임
long long infiniteSequence(long long n, long long p, long long q) {
    if (n == 0) return 1; // base case
    if (dp.find(n) != dp.end()) return dp[n]; // 이미 계산된 값이 있다면 사용
    //if(dp[n]) return dp[n]; //이렇게 해도 가능함 이미 계단된 값이 있이면 반환
    return dp[n] = infiniteSequence(n / p, p, q) + infiniteSequence(n / q, p, q);
    //재귀적으로 값을 반환하여 계산
}

int main() {
    long long n, p, q;
    cin >> n >> p >> q;
    cout << infiniteSequence(n, p, q) << endl;
    return 0;
}
