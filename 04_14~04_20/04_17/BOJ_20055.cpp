#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char,int> trash;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void initial(){
    string keys = "PCVSGF"; // 재활용 가능한 6종류
    int value;
    for(char key : keys){
        cin >> value;
        trash[key] = value;
    }
    cin >> trash['O']; // 일반 쓰레기 비용은 따로 입력
}
int main(){
    init();
    int N;
    cin >> N;
    vector<string> st(N);
    for(int i=0; i<N; i++){
        cin >> st[i];
    }
    initial();
    int result = 0;
    for(int i=0; i<N; i++){ 
        string result_st = st[i];
        bool check = false;
        for(char c : result_st){
            if(c != result_st[0]){ 
                check = true;
                break;
            }
        }
        if(check){
            result += trash['O'] * result_st.size();
        }
        else{
            result += trash[result_st[0]] * result_st.size();
        }
    }
    cout << result << '\n';
    return 0;
}
