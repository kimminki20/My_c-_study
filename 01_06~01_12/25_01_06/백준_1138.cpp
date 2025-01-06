//백준 1138 한 줄로 서기
#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[11];
vector<int> v;

int main() {
    cin >> N; //사람수 입력
    for(int i=0;i<N;i++){
        cin >> arr[i]; //왼쪽에 몇명이 있는 지 확인
    }
    for(int i=N-1;i>=0;i--) {
        vector<int>::iterator iter=v.begin(); //배열을 거꾸로 탐색하며 사람 배치
        // vector<int>::iterator는 항상 v.begin() 즉 처음부터 배치하기 위함.
        for(int j=0;j<arr[i];j++) 
            iter++;
        v.insert(iter,i+1); //한칸 밀어내면서 값 넣기
    }    

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
}