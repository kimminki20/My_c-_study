//백준 11047 동전0
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,K; //N은 동전 종류,K는 가치의 합
    int Cnum = 0;
    cin >> N >> K;
    vector<int> coin(N);
    for(int i=0; i<N; i++){
        cin >> coin[i];
    } //동전의 종류를 입력해줌
    int j = N-1;
    while(K!=0){
        /*if(K % coin[j] == K)
            j--;
        else{
            Cnum += K / coin[j];
            K %= coin[j];
        }*/
       if (K >= coin[j]) { // 동전이 가치보다 작거나 같으면
            Cnum += K / coin[j]; // 동전 개수를 추가
            K %= coin[j]; // 남은 가치 업데이트
        }
        j--; // 동전 인덱스 감소
        //이 부분이 더 코드가 깔끔하게 작성 가능.
    }
    cout << Cnum << endl;
}