//LCS dp 동적계획법으로 구현하기
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int LCS(string str1, string str2){
    int m = str1.length();
    int n = str2.length();
    //동적 프로그래밍을 통한 LCS 계산 테이블 초기화
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    //동적 프로그래밍을 통해 LCS 길이 계산 
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(str1[i-1] == str2[j-1]){ //현재 문자열이 같은 경우
                dp[i][j] = dp[i-1][j-1] +1;
            }
            else{ //문지열이 같지않은 경우
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    cout << LCS(str1,str2) << endl;
}