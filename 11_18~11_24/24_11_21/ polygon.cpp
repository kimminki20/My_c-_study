//백준 3049 다각형의 대각선
#include <iostream>

using namespace std;

int cal(int x){
    return (x*(x-1)*(x-2)*(x-3))/24;
}

int main(){
    int N;
    cin >> N; 
    cout << cal(N) <<endl; 
}
//수학적 아이디어가 필요했음
/* 1.하나의 교차점을 만들기 위해서는 2개의 선분이 필요
   2. 선분 2개는 4개의 꼭짓점으로 구성
   3. N개의 꼭짓점으로 구성된 블록 다각형은 하나의 교차점을 위해서는 4개의 꼭짓점 선택
   4. 따라서 nC4의 형태
*/