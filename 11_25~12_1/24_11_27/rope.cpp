//백준 2217 로프
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v1(N);
    for(int i=0; i<N; i++){
        cin >>v1[i];
    }
    sort(v1.begin(),v1.end()); //오름 차순으로 정렬

    int maxWeight = 0;
    for(int i=0; i<N; i++){
        int weight = v1[i] * (N-i);
        maxWeight = max(maxWeight,weight);
    }
    cout << maxWeight << endl;
}

//백준 2217 로프
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v1(N);
    vector<int> v2; 
    for(int i=0; i<N; i++){
        cin >>v1[i];
    }
    sort(v1.begin(),v1.end()); //오름 차순으로 정렬

    for(int i=0; i<N; i++){
        int a = 0;
        a = v1[i] * (N-i);
        v2.push_back(a);
    }
    int max = *max_element(v2.begin(),v2.end());

    cout << max << endl;
}
// 문제 내에서 "각각의 로프는 그 굵기나 길이가 다르기 때문"라고 했기에 같은 로프는 없다.