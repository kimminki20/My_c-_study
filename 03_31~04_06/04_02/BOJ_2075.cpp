//백준 2075 N번째 큰수
// https://www.acmicpc.net/problem/2075
#include <iostream>
#include <queue>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int N;
    cin >> N; //행렬의 크기
    vector<int> v; //벡터 선언
    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙 선언
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int num;
            cin >> num; //행렬의 원소 입력
            pq.push(num); //최소 힙에 원소 추가
            if(pq.size() > N){ //힙의 크기가 N보다 크면
                pq.pop(); //최소값 제거
            }
        }
    }
    cout << pq.top() << endl; //N번째 큰 수 출력
    return 0;
}

/*우선순위큐 (priority_queue) 사용법
 1. 기본적으로 최대 힙으로 동작 -> 가장 큰 원소가 top에 위치
 2. 최소 힙으로 사용하고 싶다면, greater<int>를 사용하여 비교 함수를 지정
 3. priority_queue<int> pq; //최대힙 -> 내림치순으로 정렬 -> top이 가장 큰 원소
 4. priority_queue<int, vector<int>, greater<int>> pq; //최소힙 -> 오름차순으로 정렬 -> top이 가장 작은 원소
 */