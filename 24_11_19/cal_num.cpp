//백준 2822번 점수 계산
#include <iostream>
#include <algorithm>

using namespace std;

void findindex(int *a,int*b,int *c){
   for(int i=0; i<5; i++){
    for(int j=0; j<8; j++){
        if(a[i] == b[j]){
            c[i] = j+1;
            break;
        }
      }
   }
}

int main(){
    int num[8] = {0,};
    int num_sort[8] = {0,};
    int num_index[5] = {0,};
    int sum =0;
    for(int i=0; i<8; i++){
        cin >> num[i];
        num_sort[i] = num[i];
    }
    sort(num,num+8,greater<int>());
    for(int i=0; i<5; i++){ 
        sum += num[i];
    }
    cout << sum << endl;
  findindex(num,num_sort,num_index);
    sort(num_index,num_index+5);
    for(int i=0; i<5; i++){
    cout << num_index[i] << " ";
    }
}