//백준 1620 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    cin.tie(0);
	ios::sync_with_stdio(0);
    
    int N,M;
    cin >> N >> M; //입력해야할 포켓몬의 개수 N, 풀어야하는 문제의 개수 M
    unordered_map<int,string> intToName;   // 번호 -> 이름 매핑
    unordered_map<string, int> nameToInt;  // 이름 -> 번호 매핑

    string name;
     for (int i = 1; i <= N; i++) {
        cin >> name;
        intToName[i] = name;
        nameToInt[name] = i;
    } 
    string query;
    for (int i = 0; i < M; i++) {
        cin >> query;
        if (isdigit(query[0])) { // 입력이 숫자인 경우
        //123입력한 경우 query[0]은 1임 isdigit하면 숫자1 나옴 따라서 숫자인 것 판명
            int number = stoi(query); //string -> int 라고 생각 stoi의 의미
            cout << intToName[number] << '\n'; //번호로 이름 나오개 하기
        } else { // 입력이 문자열인 경우
            cout << nameToInt[query] << '\n'; //문자열로 숫자 나오게하기
        }
    }

    return 0;
}