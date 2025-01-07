//백준 10816 숫자카드2
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    unordered_map<int,int> input; 
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        input[num]++;
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int output;
        cin >> output;
        cout << input[output] << " ";
    }
    return 0;
}