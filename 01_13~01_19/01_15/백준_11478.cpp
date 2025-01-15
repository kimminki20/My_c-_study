//백준 11478번 서로 다른 부분 문자열 개수
//문자열 집합에서 중복되지 않는 부분은 몇개인가?
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string input;
    cin >> input; //문자열 입력받음
    int N = input.size();
    set<string> result;
    for(int i=0; i<N; i++){//시작위치
        string temp = "";
        for(int j=i; j<N; j++){ //끝나는 부분 위치
            temp += input[j];
            result.insert(temp);
        }
    }
    cout << result.size() << endl;

    return 0;
}
/*for문의 실행 순서
 for(초기값; 조건; 증감)구조로 이루어짐
 조건 검사 ->(조건이 참인 경우)본문 실행 -> 증감 순서로 진행
*/