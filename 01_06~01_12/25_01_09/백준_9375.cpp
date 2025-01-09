//백준 9375 패션왕 신해빈
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N; //testcase

    for(int i=0; i<N; i++){
        map<string,int> m;
        int M;
        cin >> M;
        for(int j=0; j<M; j++){
            string s1,s2;
            cin >> s1 >> s2; // name, type
            if(m.find(s2) == m.end()){
                m.insert({s2,1}); //map에 key값으로 의상종류를 넣어주고 value 값으로 1을
            }
            else{
                m[s2]++; //있으면 값 증가
            }
        }
        int ans = 1;
        for(auto i : m){
            ans *= (i.second +1); //의상의 종류에 그 의상을 입지 않은 경우의 수를 더해서 모두 곱함
        }
        ans -=1;
        cout << ans<< '\n';  //둘 다 안입는 경우를 뺀 것 -1.
    }
    return 0;
}