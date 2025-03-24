//백준 21921 블로그

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,x; //블로그 시작한 일수, 기간
    cin >> N >> x;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    } //방문자 수를 입력
    int max_member = 0;
    int start=0,end = N-1,end_point = 0,count = 0;
    for(int i=0; i<N; i++){
        int record_member = 0;
        for(int j=0; j<x; j++){ //x번 반복
            record_member += v[i+j];
            end_point = i+j;
        }
        if(max_member < record_member){
            max_member = record_member;
            count =1;
        }
        else if(max_member == record_member) count++;
        
        if(end_point == end) break;
    }
    if(max_member == 0){
        cout << "SAD";
    }
    else{
        cout << max_member << '\n' << count;
    }
}
    해당 방법처럼 하면 값들은 잘 나오지만 시간초과 발생 for문을 2번써서 그런듯
    */
   #include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, x;
    cin >> N >> x;  // n: 전체 숫자의 개수, x: 연속된 부분의 길이

    int sum = 0;  // 현재 부분합을 저장할 변수
    int arr[250000];  // 최대 입력 크기에 맞춘 배열 선언
    for (int i = 0; i < x; i++) {// 처음 x개의 숫자를 입력받아 초기 부분합 계산
        cin >> arr[i];
        sum += arr[i];
    }
    int answer = sum; // 최대 합 초기값 설정
    int cnt = 1; // 최대 합이 나타난 횟수 (처음에는 1번 발생)
    for (int i = x; i < n; i++) {// 슬라이딩 윈도우 기법을 이용하여 나머지 숫자를 처리
        cin >> arr[i];  // 새로운 숫자 입력
        sum += arr[i] - arr[i - x];  // 새로운 숫자를 더하고, 가장 오래된 숫자를 뺌
        if (sum >= answer) { // 현재 부분합이 최대 합과 같거나 크다면
            if (sum == answer) { 
                cnt++; // 같은 최대 합이 나온 경우 횟수 증가
            } else {
                answer = sum; // 더 큰 최대 합이 나오면 갱신
                cnt = 1; // 새로운 최대 합이므로 횟수 초기화
            }
        }
    }
    if (answer == 0) { // 최대 합이 0이라면 "SAD" 출력
        cout << "SAD";
    } else {
        cout << answer << '\n' << cnt;  // 최대 합과 그 합이 나온 횟수 출력
    }

    return 0;
}

