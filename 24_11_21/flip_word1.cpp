#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int N;
    cin >> N;
    cin.ignore();
    while(N--){
        string s = "";
        getline(cin,s);
        s += ' ';
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]== ' '){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                } //넣은것 반대로 출력
                cout << s[i]; //공백 출력
            }
            else
                st.push(s[i]); //문자를 만났기에 push
        }
    }
}