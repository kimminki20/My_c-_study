//백준 10867 중복 빼고 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, a;
    vector<int> v;
    // 입력 받기
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
    // 정렬
    sort(v.begin(), v.end());
    // 중복 제거 
    //unique 함수는 중복된 원소들을 모아둔 뒷부분의 첫번째 원소 주소 리턴
    //그 첫번째 주소부터 마지막까지의 범위에 있는 원소들을 erase
    /*ex) 1,1,2,3,4,4,5,6 -> 1,2,3,4,5,6,1,4로 정렬 후 뒤로 밀린 1 리턴
        뒤로 밀린 1부터 끝까지 erase하는 것.
    */
    v.erase(unique(v.begin(), v.end()), v.end());
    // 출력
    for (int num : v) {
        cout << num << " ";
    }
    return 0;
}
