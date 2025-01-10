//백준 1764 듣보잡 한번에 맞춤
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N >> M; //듣도 못한 사람 N,보도 못한 사람 M
    set<string> unheard; //듣도 못한
    set<string> result;
    for(int i=0; i<N; i++){
        string st;
        cin >> st;
        unheard.insert(st);
    }//듣도 보다 못한 사람 set으로 넣음. 바로 정렬
    int count = 0;
    for(int i=0; i<M; i++){
        string st;
        cin >> st;
        auto it = unheard.find(st);
        if(it != unheard.end()){
            result.insert(st);
            count++;
        }
    }
    cout << count << '\n';
    //count 안쓰고 result.size()를 쓰는 것도 방법일듯
    for(const string& st : result){
        cout << st << '\n';
    }
}