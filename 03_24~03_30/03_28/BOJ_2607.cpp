//백준 2607 비슷한 단어
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void init(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int N; //단어의 개수 
    cin >> N; 
    vector<string> input(N);
    string str;
    for(int i=0; i<N; i++){
        cin >> input[i];
        }
    str = input[0]; //맨 위에 있는 값은 기준 문자
    sort(str.begin(),str.end()); // 오름차순 정렬
    int count = 0;
    for(int i=1; i<N; i++){
        string cmp = input[i];
        sort(cmp.begin(),cmp.end()); //정렬해서 대기
        int match = 0;
        if(str.size() == cmp.size()){// 바꾼 경우 or 구성이 같은 경우
            if(str == cmp) count++; //구성이 같은 경우
            else{ //바꾼 경우
                for(int i=0; i<str.size(); i++){ 
                    for(int j=0; j<cmp.size(); j++){
                        if(str[i] == cmp[j]) match++;
                    }
                }
                if(str.size() - 1 == match)count++;
            }
        }
        else if(str.size() > cmp.size()){ // 뺀 경우
            for(int i=0; i<str.size(); i++){ 
                for(int j=0; j<cmp.size(); j++){
                    if(str[i] == cmp[j]) match++;
                }
            }
            if(str.size() - 1 == match)count++;
        }
        else{ // 더한 경우
            for(int i=0; i<str.size(); i++){ 
                for(int j=0; j<cmp.size(); j++){
                    if(str[i] == cmp[j]) match++;
                }
            }
            if(str.size() <= match) count++;
        }
    }
    cout << count;
    }

    // 6%에서 틀렸음 다시! -> 효율성과 알려준 입력값에 대해서만 값이 나오도록 치중.

//vector에 알파벳의 개수를 미리 카운트해두고 그걸 가지고  합을 생각하는 방법으로 코드 구현
//백준 2607 비슷한 단어
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void init() { 
    ios_base::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int N; // 단어의 개수
    cin >> N;
    vector<string> input(N); // 입력 단어 저장 벡터
    for (int i = 0; i < N; i++) {
        cin >> input[i]; // 단어 입력
    }

    string str = input[0]; // 기준 단어 설정
    vector<int> base(26, 0); // 기준 단어의 문자 개수 배열 (A-Z)
    for (char c : str) {
        base[c - 'A']++; // 기준 단어의 각 문자 개수 카운트
    }

    int count = 0; // 비슷한 단어 개수 저장
    for (int i = 1; i < N; i++) {
        string cmp = input[i]; // 비교 대상 단어
        vector<int> target(26, 0); // 비교 단어의 문자 개수 배열
        for (char c : cmp) {
            target[c - 'A']++; // 비교 단어의 각 문자 개수 카운트
        }

        int diff_plus = 0; // 기준 단어보다 많은 문자 개수 합
        int diff_minus = 0; // 기준 단어보다 적은 문자 개수 합
        for (int j = 0; j < 26; j++) {
            int diff = target[j] - base[j]; // 문자 개수 차이 계산
            if (diff > 0) diff_plus += diff; // 더 많은 경우 합산
            else if (diff < 0) diff_minus -= diff; // 더 적은 경우 합산
        }

        // 비슷한 단어 조건 체크
        if (diff_plus == 0 && diff_minus == 0) { // 구성이 동일한 경우
            count++;
        } else if (diff_plus == 1 && diff_minus == 0) { // 한 글자 더한 경우
            count++;
        } else if (diff_plus == 0 && diff_minus == 1) { // 한 글자 뺀 경우
            count++;
        } else if (diff_plus == 1 && diff_minus == 1) { // 한 글자 바꾼 경우
            count++;
        }
    }

    cout << count; // 비슷한 단어 개수 출력
    return 0;
}