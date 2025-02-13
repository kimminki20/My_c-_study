//백준 1244 스위치 켜고 끄기 최적화
#include <iostream>
#define switch_max 102
using namespace std;

int main(){
    int N; // 스위치 개수
    int arr[switch_max] = {0,}; // 스위치를 저장할 공간
    cin >> N;

    // 스위치 상태 입력
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    int student;
    cin >> student; // 학생의 수

    for(int i = 0; i < student; i++){
        int sex, num;
        cin >> sex >> num;

        if(sex == 1){ // 남학생
            int temp = num;
            while(temp <= N){  // 마지막 스위치도 포함해야 함
                arr[temp] = 1 - arr[temp]; // 0->1, 1->0
                temp += num;
            }
        }
        else{ // 여학생
            arr[num] = 1 - arr[num]; // 자기 자신 반전
            int left = num - 1, right = num + 1;

            // 대칭 조건 확인
            while(left >= 1 && right <= N && arr[left] == arr[right]){
                arr[left] = 1 - arr[left];
                arr[right] = 1 - arr[right];
                left--;
                right++;
            }
        }
    }

    // 20개씩 출력
    for(int i = 1; i <= N; i++){
        cout << arr[i] << ' ';
        if(i % 20 == 0) cout << '\n';
    }

    return 0;
}
