//백준 2146 카드2
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    queue <int> card;
    for(int i=0; i<N; i++){
        card.push(i+1);
    } //큐에 입력받은 N까지 값을 넣음
    while(card.size() != 1){
        card.pop(); // 맨 위의 카드를 버림
        int front;
        front = card.front();
        card.pop();
        card.push(front); //제일 위의 카드를 제일 아래 카드 밑으로 옮김
    }
    cout << card.front();
}

/*
    동작을 카드가 한 장 남을 때까지 반복하게 된다. 우선, 제일 위에 있는 카드를 바닥에 버린다. 
    그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
    해당 과정 처럼 하나를 버린다 pop(), 맨 위에 카드를 맨 아래로 보낸다 -> queue 사용
*/