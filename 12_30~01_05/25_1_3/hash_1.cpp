//코딩테스트 c++로 합격자되기 두 개의 수 합 찾기
#include <iostream>
#include <vector>

using namespace std;

void mapping(vector<int>&hash, const vector<int> &arr, int target){
    for(int i=0; i< arr.size(); i++){
        if(arr[i] > target)
            continue;
        hash[arr[i]] = 1;
    }
}
bool solution(vector<int> arr, int target){
    vector<int>hash(target+1,0); //target+1개의 공간이 있는 hash 벡터 생성
    mapping(hash,arr,target); //hash table 생성

    for(int i=0; i<arr.size(); i++){
        int num = target - arr[i];
        if(num == arr[i])
            continue;
        if(num < 0)
            continue;
        if(hash[num])
           return true;
    }
    return false;
}
int main(){
    vector<int> arr;
    int N,target; //v벡터의 원소 개수, target 값.
    cin >> N >> target;
    for(int i=0; i<N; i++){
        cin >> arr[i]; //값 입력
    }
    if(solution<(arr,target)){
        cout << "합이 " <<target << "인 두 숫자가 존재함";
    }
    else{
            cout << "합이 " <<target << "인 두 숫자가 존재하지 않음";
    }
    return 0;
}