//백준 2304 창고 다각형 
// https://www.acmicpc.net/problem/2304

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int N;
    cin >> N; //창고 기둥의 개수
    vector<int> v(1001,0); //전체 벡터
    vector<pair<int,int>> arr(N); //기둥의 위치와 높이 저장
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second; //기둥의 위치와 높이 입력
    }
    sort(arr.begin(), arr.end()); //기둥의 위치를 기준으로 정렬
    int max_height = 0; //최대 높이
    int max_index = 0; //최대 높이의 인덱스
    for(int i=0; i<N; i++){
        if(arr[i].second > max_height){ //최대 높이 갱신
            max_height = arr[i].second;
            max_index = arr[i].first;
        }
        v[arr[i].first] = arr[i].second; //기둥의 위치와 높이 저장
    }
    //여기서부터 넓이 계산
    int area = 0; //넓이
    int left = 0; //왼쪽 기둥
    int right = 0; //오른쪽 기둥
    for(int i=0; i<=max_index; i++){
        if(v[i] > left){ //왼쪽 기둥의 높이 갱신
            left = v[i];
        }
        area += left; //넓이 계산
    }
    for(int i=arr[N-1].first; i>max_index; i--){
        if(v[i] > right){ //오른쪽 기둥의 높이 갱신
            right = v[i];
        }
        area += right; //넓이 계산
    }
    cout << area << endl; //결과 출력
    return 0;
}