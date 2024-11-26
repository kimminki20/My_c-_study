#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::vector<int> v = {4,2,5,3,1};
    sort(v.begin(),v.end()); //1,2,3,4,5 오름차순으로 정렬
    sort(v.rbegin(),v.rend()); // 5,4,3,2,1 내림차순으로 정렬
    return 0;
}

/* sort() - 2개 인자만 사용
   -> 시작 반복자와 끝 반복자를 받아 범위 내 원소들을 오름차순,내림차순으로 정렬
*/