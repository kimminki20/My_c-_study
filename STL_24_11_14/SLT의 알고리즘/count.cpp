#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v = {1,4,3,4,5,4,5};

    int ret = count(v.begin(),v.end(),5); // 5라는 값이 벡터 안에서 얼마나 있는 지 찾기
    cout << ret << endl; // 2출력

    return 0;
}

/* count() 함수
    -컨테이너 내에서 특정 값을 나타나는 횟수를 셈.
    -인자는 3개를 받음 시작 반복자부터 끝 반복자까지 범위,3번째 인자의 값
    - 3번째 인자의 값과 일치하는 원소의 개수를 반환
*/