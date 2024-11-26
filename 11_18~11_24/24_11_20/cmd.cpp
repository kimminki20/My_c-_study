//백준 1032 명령 프롬프트
/*2차원 배열을 선언하여 각각의 행마다 열의 원소를 비교하여 같으면 그대로 출력하고 
  같지 않다면 ?로 출력하는 표현을 생각*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
 int a= 0;
 cin >> a; // 입력받아야하는 수
 vector<vector<char>>v(a); //행의 갯수만 알고 열의 갯수는 모르는 경우로 생각
 for(int i=0; i<a; i++){
    string input;
    cin >> input;
    for(char c : input){
        v[i].push_back(c);
    }
 }
 char buffer[51] ={0};
 int len = v[0].size(); //첫번째 행의 열의 개수
 //size는 함수임 따라서 size()로 사용해야함.
 
for(int i=0; i<len; i++){ 
    char check = v[0][i];
    bool isSame = true; //같은지 판단

    for(int row = 1; row <a; row++){
        if(v[row][i] != check){
            isSame = false;
            break;
        }
    }
    if(!isSame){ //!isSame이기에 T가 되고 값이 다른 것임 따라서 ?로 출력
        buffer[i] = '?';
    }else{
        buffer[i] = check;
    }
 }
 buffer[len] = '\0'; // null-terminate 추가
    cout << buffer << endl;

    return 0;
}
