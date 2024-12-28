#include <iostream>
#include <vector>
#include <algorithm> // sort를 위해 필요

using namespace std;

int main() {
    int N;
    cin >> N; // 수열의 크기 입력
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i]; // 벡터에 값 넣기
    }
    int x;
    cin >> x; // 자연수 x
    // 벡터 정렬
    sort(v.begin(), v.end());
    // 투 포인터 초기화
    int left = 0, right = N - 1, count = 0;

    while (left < right) {
        int sum = v[left] + v[right];

        if (sum == x) {
            count++;  // 두 수의 합이 x인 경우
            left++;
            right--;
        } else if (sum < x) {
            left++;  // 합이 x보다 작으면 왼쪽 포인터를 이동
        } else {
            right--; // 합이 x보다 크면 오른쪽 포인터를 이동
        }
    }

    cout << count;
    return 0;
}
