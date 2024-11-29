#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string word;
    int len;
    
    cin >> word;
    len = word.length(); 
    string arr[len] = {};
    
    for (int i = 0; i < len; i++) {
        arr[i] = word.substr(i, len); //  word의 인덱스 i부터 len 전까지 문자열을 자르는 것
    }
    
    sort(arr, arr + len); //배열의 시작주소인 arr와 마지막인 arr+len으로 설정 즉 오름차순 중렬
    
    for (int i = 0; i < len; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}