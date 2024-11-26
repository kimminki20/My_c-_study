//백준 10867 중복 빼고 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int N,a;
    vector<int> v;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a;
        v.push_back(a);
    } //값 입력
    sort(v.begin(),v.end()); //오름차순 정렬
    for(int i=0; i<v.size(); i++){
        if(i == 0 || v[i] != v[i-1]){
            cout << v[i] << " ";
        }
    }
    return 0;
}