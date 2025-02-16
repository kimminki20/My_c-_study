/*
이진탐색을 사용해서 7795 먹을 것인가 먹힐 것인가 풀이
lower_bound
용도 : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
⭐ 사용 조건 : 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 함
upper_bound
용도 : 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
⭐ 사용 조건 : 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 함
*/
#include <iostream>
#include <vector>
#include <algorithm> // sort, lower_bound

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    vector<int> result;

    while (test_cases--) {
        int N, M;
        cin >> N >> M;

        vector<int> v1(N);
        vector<int> v2(M);

        for (int i = 0; i < N; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> v2[i];
        }

        // 정렬
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int count = 0;
        for (int i = 0; i < N; i++) {
            // v1[i]보다 작은 값들의 개수를 찾음
            // v1[i] 이상이 처음 등장하는 위치를 반환
            int smaller_count = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
            count += smaller_count;
        }

        result.push_back(count);
    }

    for (auto i : result) {
        cout << i << '\n';
    }

    return 0;
}
