//백준 1475번 6,9를 처리하는 부분을 더 깔끔하게 푼 부분
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr_1; // 입력받은 값을 분해해서 저장
int N;

void save() {
    while (N / 10 != 0) {
        arr_1.push_back(N % 10);
        N /= 10;
    }
    arr_1.push_back(N);
}

int count() {
    vector<int> result(10, 0); // 각 숫자의 개수를 저장
    for (int i = 0; i < arr_1.size(); i++) {
        result[arr_1[i]]++;
    }

    // 6과 9를 합쳐 처리
    int combined = result[6] + result[9];
    result[6] = (combined + 1) / 2; // 올림 처리
    result[9] = result[6];

    // 최댓값 찾기
    int max_value = *max_element(result.begin(), result.end());
    return max_value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    save(); // 입력받은 값을 arr_1에 저장
    int max_sets = count(); // 필요한 세트의 최댓값 계산
    cout << max_sets << endl;

    return 0;
}

