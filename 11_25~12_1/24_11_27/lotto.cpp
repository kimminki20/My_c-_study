#include <iostream>
using namespace std;

int K;
int arr[13], selected[6];

void backTracking(int cur, int len) {
    if(len == 6) {
        for(int x : selected) cout << x << ' ';
        cout << '\n';
        return;
    }
    for(int i = cur + 1; i < K; i++){
        selected[len] = arr[i];
        backTracking(i, len+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //이거쓰면 속도가 빨라짐(백준 참고)
    while(true) {
        cin >> K;
        if(!K) return 0;
        for(int i=0; i<K; i++) cin >> arr[i];
        backTracking(-1, 0);
        cout << '\n';
    }
}