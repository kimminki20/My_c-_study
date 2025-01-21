//백준 18258 큐2
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    queue<int> q;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string st;
        cin >> st;
        if(st == "push"){
            int in;
            cin >> in;  
            q.push(in);
        }
        if(st == "front"){
            if(!q.empty()){
                cout << q.front() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        if(st == "back"){
            if(!q.empty()){
                cout << q.back() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        if(st == "empty"){
            if(!q.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << 1 << '\n';
            }
        }
        if(st == "size"){
            cout << q.size() << '\n';
        }
        if(st == "pop"){
            int out;
            if(!q.empty()){ //비어있지않음
                out = q.front();
                cout << out << '\n';
                q.pop();
            }
            else{
                cout << -1 << '\n';
            }
        }
    }

}