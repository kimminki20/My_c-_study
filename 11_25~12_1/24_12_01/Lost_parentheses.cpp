//백준 1541 잃어버린 괄호
#include <iostream>
#include <string>

using namespace std;

int main(){
    string st; // 입력받을 식 
    bool check = false; // - 판별
    string num = ""; // 식에서 쓴 숫자
    int min_aws = 0; // 식의 최소값
    
    cin >> st;
    for(int i=0; i<= st.size(); i++){
        //기호를 만나거나 식이 끝날 경우
        if(st[i] == '-' || st[i] == '+' || i == st.size()){
            if(check == true){ //앞서 '-'가 있다면 숫자 빼줌
                min_aws -= stoi(num);
                num = "";
            } // '-'가 없으므로 숫자 더해줌
        else if(check == false){
            min_aws += stoi(num); //글자를 정수로
            num = "";
        }
    } // 기호가 아니라 숫자인 경우
    else{
        num += st[i]; //문자열 형태로 숫사 지정
    }
    if(st[i] == '-'){
        check = true;
        }
    }
    cout << min_aws;
    return 0;
}