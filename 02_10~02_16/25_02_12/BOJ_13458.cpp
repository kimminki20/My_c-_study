//백준 13458 시험 감독
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(){
    int N,B,C;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }//시험장에 몇명이 있는지 입력
    cin >> B >> C; //총 감독관이 감시 가능 B명, 부감독관이 감시 가능 C명
    ll max_people = 0;
    for(int i=0; i<N; i++){
        int num = v[i];
        if(num - B <= 0){ //총감독관으로 모두 커버가 가능한 경우
            max_people++;
            continue;
        }
        else{ //총감독관으로 커버가 모두 안되는 경우
            max_people++; //총감독관 숫자 미리 하나 더하고
            num -= B; //총 감독관으로 커버되는 사람 빼서 num값 수정
            if(num % C == 0){
                max_people += (num / C);
            }
            else{
                max_people = max_people + num / C + 1;
            }
        }
    }
    cout << max_people;
}