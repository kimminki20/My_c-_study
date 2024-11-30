//백준  28278 스택2
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,a,num;
    cin >> N; //명령수 N
    stack<int> st;
    for(int i=0; i<N; i++){
        cin >> a;
        switch (a)
        {
        case 1: //push
            cin >> num;
            st.push(num);
            break;
        case 2: //맨 위의 정수 빼고 출력
            if(!st.empty()){ //비어있지않으면 출력
            int b = st.top();
            cout << b << endl;
            st.pop();}
            else{ //값이 비어있으면 -1 출력
                cout << "-1" << endl;
            }
            break;
        case 3: //들어있는 정수의 개수 즉,사이즈
            cout << st.size() << endl;
            break;
        case 4: //st.empty() -> 비어있으면 1임을 생각 
            if(st.empty())
                cout << "1" << endl;
            else cout << "0" << endl;
            break;
        case 5:  
        if(!st.empty()){ //비어있지않으면 출력
            int b = st.top();
            cout << b << endl;
            }
        else{
            cout << "-1" << endl;
        }
            break;
        }
    }
    return 0;
}
//실행된 값은 맞게 나오나 시간이 오래걸리는 문제로 switch 보다는 while문으로 다시 풀음.