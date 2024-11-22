#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;

    int A = 1, B = 0; // 초기 상태: A=1, B=0

    while (K--) { // K 단계 반복
        int newA = B; // 새로운 A의 개수는 이전 단계의 B 개수
        int newB = A + B; // 새로운 B의 개수는 이전 A와 B의 합
        A = newA;
        B = newB;
    }

    cout << A << " " << B << endl; // 최종 결과 출력
    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int main() {
    int k, a,b;
    cin >> k;
    
    vector<ci> v(k+1);  // {A 갯수, B 갯수}
    v[0] = {1, 0};
    for(int i=1; i<=k; i++) {
        a = v[i-1].first;
        b = v[i-1].second;
        v[i] = {b, a+b};
    }
    
    cout << v[k].first << " " << v[k].second;
    
    return 0;
}
*/
