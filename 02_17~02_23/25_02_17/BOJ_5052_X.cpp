//백준 5052 전화번호 목록
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int test_case;
    cin >> test_case;
    while(test_case--){
        int n;
        cin >> n;
        vector<string> v;
        for(int i=0; i<n; i++){
            string number;
            cin >> number;
            v.push_back(number);
        } //벡터에 값 입력

    }
}
//트라이 , 트리에 대한 공부를 한 후에 다시 도전