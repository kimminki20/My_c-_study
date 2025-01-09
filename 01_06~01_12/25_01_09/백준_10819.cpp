//백준 10819 차이를 최대로
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr; //push_back쓸꺼면 크기정해놓지않고 설정하기
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }//배열의 값을 입력함
    sort(arr.begin(),arr.end()); //오름 차순으로 정렬
    vector<int> result(N);
    int sum = 0;
    if(N%2 == 0){ //짝수인경우는 딱 맞게 떨어짐 즉 N/2만큼만 for문을 돌아도 끝
        for(int i=0; i<N/2; i++){
            result.push_back(arr[i]);
            result.push_back(arr[N-i-1]);
        }
    }   
    else{ //홀수 인경우
        for(int i=0; i<(N/2)+1; i++){
            if(i == N-i-1){
                result.push_back(arr[i]);
            }
            else{
            result.push_back(arr[i]);
            result.push_back(arr[N-i-1]);
            }
        }
    }
    /*
    위에 처럼 2개로 나누는 것보다 두 포인터를 사용해서 옮기는 것이 코드가 깔끔함 
     int left = 0, right = N - 1;
    // 두 포인터를 사용하여 번갈아 배열에 값을 넣기
    while(left <= right) {
        if(left == right) {
            result.push_back(arr[left]); // 중간 값이 남으면 하나만 넣음
            break;
        }
        result.push_back(arr[right--]);
        result.push_back(arr[left++]);
    }
    */
    for(int i=0; i<N-1; i++){
        sum += abs(result[i] - result[i+1]);
    }
    cout << sum <<endl;
} //이렇게 풀면 되는줄 알았는데 값이 나오지않는다.
