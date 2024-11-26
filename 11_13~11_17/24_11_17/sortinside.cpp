//백준 1427 소트인사이드
#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    string str;
    cin>>str;
    sort(str.begin(), str.end(), greater<char>());
    cout<<str;
}
//sort알고리즘을 사용하여 쉽게 구현.