//백준 1966번 프린터 큐
#include <iostream>
#include <queue>

using namespace std;
int main(){
    int T_case = 0,N,M,priority;
    cin >> T_case; //테스트 케이스 수 입력
    for(int i=0; i<T_case; i++){
      int count = 0;
      queue<pair<int,int>> q; //인덱스와 우선순위를 저장하는 일반 큐.
      priority_queue<int>printer; //우선순위를 저장하는 우선순위 큐.
      cin >> N >> M; //문서의 갯수, 내가 찾고싶은 index 번호
        for(int j=0; j<N; j++){
            cin >> priority;
            q.push({j,priority}); //index와 우선순위를 저장
            printer.push(priority); //각 문서의 우선순위 저장 (내림차순 정렬됨)
        }
        while(!printer.empty()){
            int idx = q.front().first; //맨 앞의 idx
            int prior = q.front().second; //맨 안의 우선순위
            q.pop(); //일단 제거
            if(printer.top() == prior){ //내림차순 정렬이기에 top의 값(= 가장 큰 우선순위)
                count++; //같은 우선순위이기에 출력++
                printer.pop();
                if(idx == M)
                {
                    cout << count << endl;
                    break;
                }
            }
            else   
                q.push({idx,prior});
        }
    }
    return 0;
}