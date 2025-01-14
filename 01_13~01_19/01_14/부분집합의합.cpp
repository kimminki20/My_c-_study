//코테합격자되기 c++편 -> 부분 집합 합 문제
//부분 집합 합(sum of subset)은 1~N까지 조합했을 때 합이 K가 되는 조합을 찾는 문제
/* 완전 탐색으로 푸는 경우: 모든 경우를 걸쳐서 생각하는 과정
    N개의 숫자를 뽑는 조합으로는 2^N개가 있으므로 시간 복잡도는 O(2^N)으로 나타냄.
    백트래킹을 사용하면 O(2^N)보다는 더 적은 시간복잡도를 갖게 되므로 백트래킹도 생각해볼 만한 알고리즘임.
*/
//정수 N을 입력받아서 1~N까지의 숫자 중에서 합이 10이 되는 조합을 배열로 반환하는 solution()짜기
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

void backtrack(int N, int sum, int start) {
    if (sum == 10) { // 합이 10이면 결과에 추가
        results.push_back(selected_nums);
        return;
    }
    for (int i = start; i <= N; i++) {
        if (sum + i <= 10) { // 합이 10보다 작거나 같으면 탐색 계속
            selected_nums.push_back(i);
            backtrack(N, sum + i, i + 1);
            selected_nums.pop_back();
        }
    }
}

vector<vector<int>> solution(int N) {
    results.clear(); // 이전 호출 결과 초기화
    backtrack(N, 0, 1); // 1부터 백트래킹 시작
    return results;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> combinations = solution(N);
    // 결과 출력
    for (const auto& combination : combinations) {
        cout << "{ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
