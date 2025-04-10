//백준 2003 수들의 합2
// https://www.acmicpc.net/problem/2003

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int N,M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int left = 0, right = 0;
    int sum = 0;
    int count = 0;
    while(right < N){ // right 포인터를 이동
        // right 포인터를 이동하며 합을 구함
        sum += arr[right];
        right++;
        while(sum > M && left < right){ // sum이 M보다 크면 left 포인터를 이동
            sum -= arr[left];
            left++;
        }
        if(sum == M){
            count++; // sum이 M과 같으면 count 증가
        }
    }
    cout << count << "\n";
    return 0;
}