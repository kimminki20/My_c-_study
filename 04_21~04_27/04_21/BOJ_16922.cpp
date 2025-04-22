//백준 16922 로마 숫자 만들기
//https://www.acmicpc.net/problem/16922
#include <iostream>
#include <set>
using namespace std;

int value[4] = {1, 5, 10, 50}; // I, V, X, L
set<int> result; //중복 제거
 
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
} //입출력 최적화 

void dfs(int depth, int sum, int n) {
     //depth: 현재까지 사용한 숫자 개수, sum: 현재까지의 합, n: 총 사용할 문자 수
    if (depth == n){ //N개 모두 사용
        result.insert(sum);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        dfs(depth + 1, sum + value[i], n);
    }
}

int main() {
    init();
    int N;
    cin >> N;
    dfs(0, 0, N); //dfs시작
    cout << result.size() << '\n';
    return 0;
}
//시간 초과발생 -> set으로 하면 자동으로 중복은 제거해주지만, 내부적으로 레드블랙 트리 구조를 사용
// 삽입할 떄마다 정렬 및 중복 확인 비용이 
// 따라서 bool check와 같은 것으로 확인하고 넘기는게 나을듯