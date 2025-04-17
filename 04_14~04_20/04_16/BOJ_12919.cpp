//백준 12919 A와 B 2
//https://www.acmicpc.net/problem/12919
//입력받은 string S,T에서 S를 T로 만드는 것이 가능하면 1출력 아니면 0출력 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    string S,T;
    cin >> S >> T; //두 문자열 S,T입력
    int num = 0; //vector에서의 번호
    vector<string> st;
    st.push_back(S);
    while(num < st.size()){
        string current = st[num++];
        if(current == T){
            cout << '1' << '\n';
            return 0;
        }
        if(current.size() < T.size()){
            string addA = current + 'A';
            string addB = current + 'B';
            reverse(addB.begin(),addB.end());
            st.push_back(addA);
            st.push_back(addB); //계속해서 넣다보면 중복되는 문자열도 들어갈 가능성 존재
        }
    }
    cout << '0' << '\n';
    return 0;
} //메모리 초과 발생
