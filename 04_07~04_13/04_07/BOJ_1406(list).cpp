#include <iostream>
#include <string>
#include <list> // STL list 사용

using namespace std;

int main(){
    int n; 
    string s;
    cin >> s;
    cin >> n;  
    // list<char>로 문자열을 저장: 문자열의 중간 삽입/삭제에 효율적
    list<char> l(s.begin(), s.end());  

    // 커서를 문자열의 끝으로 초기화
    auto cursor = l.end(); 
    
    while(n--){ // 명령어 개수만큼 반복
        char tmp;
        cin >> tmp; // 명령어 입력
        
        if(tmp == 'L'){ // 커서를 왼쪽으로 한 칸 이동
            if( cursor != l.begin()){ // 커서가 문자열 시작이 아니라면
                cursor--; // 왼쪽으로 이동
            }
        } 
        else if(tmp == 'D'){ // 커서를 오른쪽으로 한 칸 이동
            if(cursor != l.end()){ // 커서가 문자열 끝이 아니라면
                cursor++; // 오른쪽으로 이동
            }
        }
        else if(tmp == 'B'){ // 커서 왼쪽 문자 삭제
            if(cursor != l.begin()){ // 시작이 아니라면
                cursor = l.erase(--cursor); 
                // now를 왼쪽으로 이동한 뒤 해당 위치의 문자를 삭제하고,
                // erase는 삭제된 다음 위치의 반복자를 반환함
            }
        }
        else if(tmp == 'P'){ // 커서 왼쪽에 문자 삽입
            char c;
            cin >> c;
            l.insert(cursor, c); // 현재 커서 앞에 문자 삽입
        }    
    }

    // 최종 결과 출력
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }

    return 0;     
}
