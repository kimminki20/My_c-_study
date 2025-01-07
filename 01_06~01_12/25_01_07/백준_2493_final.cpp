//백준 2493 탑 stack
#include <iostream>
#include <stack>

using namespace std;

int N,K;
stack<pair<int,int>> st; //(index,value)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N; //탑의 수
    for(int i=1; i<=N; i++){
        cin >> K; //비교할 값
        if(st.empty()){
            st.push({i,K});
            cout << "0 ";
        }
        else{
            while(!st.empty()){ //신호 수신 가능
                if(st.top().second > K){ 
                    cout << st.top().first << " ";
                    break;//index 출력
                }
                else{
                    st.pop(); //신호 수신 불가시 pop
                }
            }
            if(st.empty())//스택 비면 0 출력
                cout << "0 "; 
            st.push({i,K});
        }
    }
}//왼쪽에 있는 것만 생각하면 된다고하면 그냥 입력하는 것들을 stack으로 생각하먄
//생각보다 쉽게 해결 할 수 있엇던 문제였음.