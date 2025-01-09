#include <iostream>
#include <cmath>

using namespace std;

int arr[8];            // 입력 배열, 최대 크기 8
int arr2[8];           // 순열을 만들기 위한 배열
int isVisited[8];      // 배열 요소가 이미 사용되었는지 체크하는 배열
int n;                 // 배열의 크기
int maxValue = -1;     // 차이의 합에서 최대값을 저장

// 깊이 우선 탐색 (DFS) 함수
void dfs(int cnt){
  if(cnt == n){ // 순열이 완성되면
    int result = 0;
    // 차이의 합 계산
    for(int i = 0; i < n - 1; i++){
      result += abs(arr2[i + 1] - arr2[i]);  // arr2 배열에서 인접한 값들의 차이의 절댓값을 더함
    }
    if(result > maxValue) maxValue = result;  // 최대값 갱신
    return;
  }

  // 배열에서 아직 사용되지 않은 원소를 선택하여 순열을 만들기
  for(int i = 0; i < n; i++){
    if(!isVisited[i]){  // 아직 방문하지 않은 원소인 경우
      isVisited[i] = true;  // 방문 처리
      arr2[cnt] = arr[i];   // arr2[cnt]에 원소 넣기
      dfs(cnt + 1);         // 재귀적으로 순열의 다음 위치로 이동
      isVisited[i] = false; // 재방문 가능하게 되돌리기
    }
  }
}

int main(){
  cin >> n;  // 배열의 크기 입력
  for(int i = 0; i < n; i++){
    cin >> arr[i];  // 배열의 원소 입력
  }

  dfs(0);  // DFS 호출, 순열 생성 시작 (0번 인덱스부터 시작)
  cout << maxValue;  // 계산된 최대 차이의 합 출력
  return 0;
}
