#include <iostream>
#include <vector>
using namespace std;

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int window_size = 1;
    int count = 0;
    while(window_size <= N){
        for(int i = 0; i <= N - window_size; i++){
            int sum = 0;
            for(int j = i; j < i + window_size; j++){
                sum += arr[j];
            }
            if(sum == M){
                count++;
            }
        }
        window_size++;
    }

    cout << count << '\n';
}
//슬라이딩 윈도우를 써서 만들었지만 반복문을 3개써서 시간 초과 발생 
//투포인터를 사용해서 시간을 줄여서 해결.
