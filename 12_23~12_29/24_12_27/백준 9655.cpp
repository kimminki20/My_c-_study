//백준 9655 돌 게임 -> 홀수면 상근 승, 짝수면 창용 승
#include <iostream>

using namespace std;
int main(){
  int N;
    cin >> N;
    if(N%2 == 1){
        cout << "SK";
    }
    else{
        cout << "CY";
    }
}