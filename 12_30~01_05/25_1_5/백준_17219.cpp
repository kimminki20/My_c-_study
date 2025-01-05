//백준 17219 비밀번호 찾기문제(해시)
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    string st1,st2;
    unordered_map<string,string> password;
    vector<string> result;
    for(int i=0; i<N; i++){
        cin >> st1 >> st2; // st1은 주소, st2는 비밀번호
       //password.insert({st1,st2}); //map으로 주소와 비밀번호를 저장
       password[st1] = st2; //주소와 비밀번호 저장
       //위의 2가지 방식으로 모두 사용 가능.
    }
    for(int j=0; j<M; j++){
        cin >> st1; //비밀번호를 찾으려고 하는 주소
        result.push_back(password[st1]);
    }
    for(const string& ch : result){
        cout << ch << "\n";
    }
}
