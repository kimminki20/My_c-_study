#include <iostream>
#include <vector>
using namespace std;

int prime(int x){
    if(x < 2) return 0;
    for(int i=2; i*i <= x; i++){
        if(x % i == 0) return 0;
    } //√x까지 검사
    return 1; //for문에서 안걸리면 소수인 것
    }  //소수인가?
/* 처음에 i*i < x로 해서 x가 정확히 어떤 소수의 제곱인 경우에도 소수로 판별할 수 있었음.
 예를 들어 x가 9인 경우 3*3이면 건너뛰게됨. 이를 수정!
*/
int palin(int x){
    vector<int> v1;
    // 숫자를 한 자리씩 분리해 v1에 저장
    while (x != 0) {
        v1.push_back(x % 10);
        x /= 10;
    }
    // 팰린드롬 확인
    vector<int> v2(v1.rbegin(), v1.rend()); // v1의 역순 벡터
    if (v1 == v2) return 1; // 팰린드롬
    return 0; // 팰린드롬이 아님
} //팰린드롬 수인가?

int main(){
    int K;
    cin >> K; //k 입력
    while(1){ //일단 무한 루프
        if(prime(K)&&palin(K)){ //소수이면 성립
                cout << K << endl;
                break;
            }
            K++;
        }
    return 0;
}
//시간이 너무 오래 걸림