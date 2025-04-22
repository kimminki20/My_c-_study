//백준 16922 로마 숫자 만들기
//https://www.acmicpc.net/problem/16922
#include <iostream>
using namespace std;

int value[4] = {1, 5, 10, 50}; // 로마 숫자 값: I, V, X, L
bool check[1001]; // 가능한 최대 합은 50 * 20 = 1000
int result_count = 0;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}//입출력 최적화

void dfs(int depth, int sum, int start, int n) {
    if (depth == n) { //depth와 같아지면 ++
        if (!check[sum]) {
            check[sum] = true;
            result_count++;
        }
        return;
    }
    for (int i = start; i < 4; ++i) {
        dfs(depth + 1, sum + value[i], i, n); // 조합으로 중복 제거
    }
}

int main() {
    init();
    int N;
    cin >> N;
    dfs(0, 0, 0, N);
    cout << result_count << '\n';
    return 0;
}
