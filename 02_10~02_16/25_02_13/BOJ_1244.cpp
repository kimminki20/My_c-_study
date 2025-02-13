//백준 1244번 스위치켜고 끄기
#include <iostream>
#define switch_max 102
using namespace std;

int main(){
    int N; //스위치 개수
    int arr[switch_max] = {0,}; //스위치를 저장할 공간할당
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        if(i == N){
            arr[i+1] = 2; //맨 끝 설정
            arr[0] = 2;
        }
    }//스위치의 상태 & 0과 1로만 결정이 되니 2 전까지만 인 것을 확인
    int student;
    cin >> student;//학생의 수
    for(int i=0; i<student; i++){
        int sex,num;
        cin >> sex >> num;
        if(sex == 1){ //남학생의 경우
            int temp = num;
            while(temp <= N){
                if(arr[temp] == 0){
                    arr[temp] = 1;
                }
                else{
                    arr[temp] = 0;
                }
                temp += num;
            }
        }
        else{//여학생의 경우
            int right = num+1,left = num-1; //투 포인터를 사용해보자
            if(arr[num] == 0) arr[num] = 1; 
            else arr[num] = 0; //여학생의 경우 입력받은 num값은 무조건 바뀌어야함
            if(left != 0 && right != N+1){ //초기에 경계값을 한번 확인함
                while(arr[right] == arr[left]){
                    if(arr[left]== 2 || arr[right] == 2) break;
                    if(arr[right] == 0){
                        arr[right] = 1;
                        arr[left] = 1;
                    }
                    else{
                        arr[right] = 0;
                        arr[left] = 0;
                    }
                    right++;
                    left--;
                }
            }
        }
    }
    for(int i=1; i<=N; i++){
        cout << arr[i] << ' ';
        if(i%20 == 0) cout << '\n';
    }
}