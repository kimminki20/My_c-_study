//백준 1475 방번호
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<int> arr = {0,1,2,3,4,5,6,7,8,9}; //세트 1개로 생각
vector<int> arr_1; //입력받은 값을 분해해서 저장
int N;
void save(){
    while(N/10 != 0){
        arr_1.push_back(N%10);
        N /= 10;
    }
    arr_1.push_back(N);
}
int count(){
    vector<int>result(10,0);
    for(int i=0; i<arr_1.size(); i++){
        result[arr_1[i]]++;
    }
    if(result[6] != result[9]){
        if((result[6]+result[9]) %2 == 0){ //짝수인 경우
            result[6] = (result[6]+result[9])/2;
            result[9] = result[6];
        }
        else{//홀수인 경우
            result[6] = (result[6]+result[9])/2+1;
            result[9] = result[6];
        }
    }
    int max_value = *max_element(result.begin(), result.end());
    return max_value;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    save(); //입력받은 값을 arr_1에 넣어서 저장함
    //reverse(arr_1.begin(),arr_1.end()); //값을 뒤집음
    cout << count();
    return 0;
}