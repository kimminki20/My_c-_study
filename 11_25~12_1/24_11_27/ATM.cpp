//백준 11399 ATM문제
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,result=0;
    cin >> N; //N명 입력
    vector<int> time(N);
    stack<int> st;
    int lated_time = 0;
    for(int i=0; i<N; i++){
      cin >> time[i];
    }
    sort(time.begin(),time.end()); //오름차순
 
    for(int i=0; i<N; i++){
        lated_time += time[i];
        st.push(lated_time);
    }
        while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result << endl;
}
