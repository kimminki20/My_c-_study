#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, length;
    cin >> N >> length;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());  // 과일 높이를 오름차순 정렬

    for (int i = 0; i < N; i++) {
        if (arr[i] <= length) {  // 현재 스네이크버드 길이로 먹을 수 있는 경우
            length++;
        } else {
            break;  // 더 이상 먹을 수 없는 경우 루프 종료
        }
    }

    cout << length << endl;
    return 0;
}
