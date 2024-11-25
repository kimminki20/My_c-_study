//백준 10845번 큐
#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main(){
    int N,K; //push할때 쓸 정수 K
    cin >> N; //명령의 수 N 입력.
    queue<int> q; //큐 선언
    string a;
    for(int i=0; i<N; i++){
        
        cin >> a; //명령어 입력
        if( a == "push"){
            cin >> K;
            q.push(K);
        }
        else if( a == "front"){
            if(q.empty()){
                cout << -1 << endl;
            } 
            else{
                cout << q.front() << endl; 
            }
        }
        else if( a== "back"){
            if(q.empty()){
                cout << -1 << endl;
            } 
            else{
            cout << q.back() << endl;
            }
        }
        else if( a == "size"){
            cout << q.size() << endl;
        }
        else if( a == "empty"){
            /*if(q.empty()) //비어 있으면 true 리턴함
                cout << true << endl;
            else
                cout << false <<endl; */
            cout << (q.empty() ? 1 : 0) << endl; // 이게 더 간결해짐
        }
        else if( a == "pop"){
            if(q.empty()){
                cout << -1 << endl;
            }    
            else{
                cout << q.front() << endl;
                q.pop(); // pop은 반환값이 없음
            }
        }
    }
    return 0;
}