//백준 17266 어두운 굴다리 이분탐색으로 푸는 방법
/* 이분탐색을 사용한 이유
    결정 함수의 단순성: 특정 H로 가능한지 확인하는 로직이 간단함. 
    첫 구간(0부터 첫 가로등), 가로등 사이, 마지막 구간(N까지)을 체크.
    각 구간의 거리가 H와 2H를 넘지 않는지 확인하면 됨.
    최적화 문제 해결: "최소 H"를 직접 구하는 대신, "H로 가능한가?"라는 질문을 반복하며 경계값을 찾음.
    이진탐색은 이런 "최소/최대" 문제를 결정 문제로 바꿔 효율적으로 풀 때 자주 사용됨(예: Parametric Search).
*/
#include <iostream>
#include <vector>
using namespace std;
 
int n, m;
vector<int> input;
int binarySearch() {
    int start = 0;
    int end = n;
    int mid;
    while(start + 1 < end) {
        bool check = false;
        mid = (start + end) / 2;
        if(input[0] > mid) check = true; //시작점(0)부터 첫 가로등까지의 거리 > mid
        for(int i = 0; i < m-1; i++) { //인접 가로등 간 거리 > mid *2
            if(input[i+1]-input[i] > mid * 2) {
                check = true;
                break;
            }
        }
        if(n-input[m-1] > mid) check = true; //마지막 가로등부터 끝점(N)까지의 거리 > mid
        
        if(check) start = mid; //높이를 늘려야하니 start = mid
        else end = mid; //높이를 줄여도 되니 end = mid
    }
    return end;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int light;
        cin >> light;
        input.push_back(light);
    }
    
    cout << binarySearch();
}