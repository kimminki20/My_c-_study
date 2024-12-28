//백준 3273 두수의 합
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N; //수열의 크기 입력
    vector<int> v;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        v.push_back(a); // 벡터에 값 넣기 
    }
    int k,count = 0; 
    cin >> k; //자연수 x
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[i]+v[j] == k){
                count++;
                break;
            }
        }
    }
    cout << count;
} //이렇게 짜면 시간초과 발생. 이중 for문 사용으로 인해서 그런 듯함.
