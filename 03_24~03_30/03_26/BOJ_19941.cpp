//백준 19941 햄버거 분배
#include <iostream>
#include <string>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int N,K,count = 0; //식탁의 길이 N, 햄버거 선택 가능 거리 K , max 인원을 count
    cin >> N >> K; //입력
    string str;
    cin >> str; //사람은 P,햄버거는 H로 입력
    for(int i=0; i<N; i++){
        if(str[i] != 'P') {
            continue; //P를 만나야 하기에 H는 패스
        }
        for(int j = i-K; j <= i+K; j++){
            if( 0 <= j && j < N && str[j] == 'H'){
                str[j] = 'C'; //햄버거를 찾으면 C로 바꿔서 중복으로 세기 방지
                count++; //사람 증가
                break;
            }
        }
    }
    cout << count;
}