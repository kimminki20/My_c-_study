//백준 1026 보물
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int sum=0;
    cin >> N; // N의 값을 설정
    vector<int> A(N);
    vector<int> B(N);
    vector<int> index(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    sort(A.begin(),A.end()); //A를 오름차순으로 정렬.
    sort(B.rbegin(),B.rend()); //B는 내림차순 정렬

    for(int i = 0; i<N; i++){
        sum +=(A[i]*B[i]);
    }
    cout << sum << endl;
    return 0;
    }

//문제에서의 B는 재배열하지말고 하는 것으로 하는 것 참고함
/*
    int maxindex = 0;
    int bsize = sizeof(B)/sizeof(B[0])
    for(int i=0; i<N; i++){
    maxindex = max_element(B,B+bsize) -B;
    result += (A[i]*b[maxindex]);
    b[maxindex] = 0;
    }
*/
/* 1.max_element(B, B + bsize)는 배열에서 가장 큰 값(5)의 주소를 반환합니다.
   2.B는 배열의 시작 주소를 나타냅니다.
   3.(max_element(B, B + bsize) - B)는 최대값의 주소에서 시작 주소를 빼서, 배열에서 최대값을 계산
*/