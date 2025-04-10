//백준 11501 주식
// https://www.acmicpc.net/problem/11501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int Testcase;
    cin >> Testcase;
    while(Testcase--){
        int Days;
        cin >> Days;
        vector<int> stock(Days);
        for(int i = 0; i < Days; i++){
            cin >> stock[i];
        } //값 입력
        int max_price = 0;
        long long profit = 0;
        for(int i = Days - 1; i >= 0; i--){ //역순으로 탐색
            //최대값을 찾고 그 최대값과 현재 주식의 차이를 profit에 더함
            //최대값을 찾는 이유는 최대값보다 작은 주식은 팔지 않기 때문
            if(stock[i] > max_price){
                max_price = stock[i]; //최대값 갱신
            }
            profit += max_price - stock[i]; //현재 주식과 최대값의 차이
        }   
        cout << profit << endl;
    }
}