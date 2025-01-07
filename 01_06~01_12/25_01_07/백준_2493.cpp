//백준 2493 탑
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v;
    vector<int> ans(N);
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    } //값을 넣음 탑의 높이 입력
    for(int i=N-1; i>=0; i--){ //N번 반복함
        int top = v[i];
        for(int j=1; j<N; j++){
            if(top < v[i-j] && i-j >= 0){
                ans[i] = i-j+1;
                break;
            }
            else if(i-j < 0){
                ans[i] = 0;
            }
        }
    }
    for(const auto &result : ans){
        cout << result << " ";
    }
    return 0;
} //이렇게 짜면 시간 초과 발생 for문을 과다 사용해서 그런 것 같음.