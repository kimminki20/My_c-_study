//LIS(최장 증가 부분 수열) dp활용해서 구현하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(const vector<int> nums){
    int n = nums.size();
    vector<int> dp(n,1);

    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){ //num[i]와 nums[j]를 비교하여 nums[i]가 더 큰 부분만 처리
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] +1);
            } //nums[j]를 이용하여 만든 부분 수열의 길이 +1 중 최대값을 저장
        }
    }
    return *max_element(dp.begin(),dp.end()); //dp벡터에서 최대값을 찾아 최장 증가 부분 수열의 길이를 반환
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> num(n)
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    cout << LIS(num) << endl;
}