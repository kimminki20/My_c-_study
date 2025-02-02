#include <iostream>

using namespace std;
using ll = long long;

ll pow(ll a, ll b, ll m) {
    if (b == 1) return a % m;  // B = 1이면 A % C를 반환
    ll val = pow(a, b / 2, m); // A^(B/2) % C를 재귀 호출
    val = val * val % m;       // val^2 % C (거듭제곱 성질 이용)
    if (b % 2 == 0) return val; // B가 짝수면 바로 반환
    return val * a % m;         // B가 홀수면 한 번 더 A를 곱해서 반환
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll A,B,C;
    cin >> A >> B >> C;
    cout << pow(A,B,C);
} 