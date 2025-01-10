//코테합격자 되기 c++편 영어 끝말잇기
/*1.참여자 수는 2<=N<=10 이하의 자연수
  2.정답은 가장 먼저 탈락하는 사람의 번호와 몇 번째 차례인지 해서 [a,b]로 출력
  3.탈락자가 생기지않으면 [0,0]으로 반환
*/
/*중복된 단어가 나오면 틀린 것으로 간주해서 [a,b]로 출력해야함 -> unodered_set 사용
*/
#include <iostream>
#include <unordered_set> //set은 자료구조 자체가 중복값 허용을 하지않음
#include <vector>
#include <string>

using namespace std;

//set이나 unordered_set의 insert 함수가 반환하는 값은 항상 pair이고, 그 중 second는 bool형으로 고정
//중복값이 아니면 true, 중복값이 나오면 false로 반환
//set은 중복값을 허용x
vector<int> solution(int n,vector<string> words){
    vector<int> answer(2,0); //정답 배열(2개의 원소) -> 순서,차례 
    unordered_set<string> usedWords;
    usedWords.insert(words[0]);
    for(int i=1; i<words.size(); i++){ //두번쨰 단아부터 끝까지 반복함
        if(!usedWords.insert(words[i]).second || words[i].front() != words[i-1].back()){
            //단어가 이미 사용했거나, 끝말잇기 규칙에 맞지 않는 경우
            //second에서 true이면 단어가 새로 추가된 경우,false면 단어가 이미 집합에 존재하는 경우
            //words[i].front() != words[i-1].back()이거는 현재 단어의 맨 처음과 이전 단어의 맨 끝이 다른경우
            //즉, 끝말잇기 조건에 부합하지않는 경우를 의미.
            answer[0] = i % n +1; // %쓰면 모듈러 연산이기에 +1해서 1~n-1의 순서로 계속 순환
            answer[1] = i / n +1; // /쓰면 몇번째 차례인지 아는 것 가능
            return answer;
        }
    }
    return answer; //문제가 없으면 [0,0] 반환 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> words;
    int N;
    cin >> N; //참여자 수
    while(1){
        string st;
        cin >> st;
        words.push_back(st);
        if( st == 'q') break;
    }
    cout << solution(N,words) << endl;
}