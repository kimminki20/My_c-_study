//백준 13335 트럭문제
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, w, l; // 트럭의 수 n, 다리 길이 w, 최대 하중 l
    cin >> n >> w >> l;
    vector<int> trucks(n);  // 트럭 무게 저장 벡터
    for (int i = 0; i < n; i++) {
        cin >> trucks[i];
    }

    queue<int> bridge;  // 다리 위의 트럭을 관리할 큐
    int bridge_weight = 0; // 현재 다리 위의 총 무게
    int time = 0;  // 경과 시간
    int index = 0; // 현재 트럭의 위치

    for (int i = 0; i < w; i++) {
        bridge.push(0);
    }// 다리의 초기 상태 (w만큼 0으로 채우기)

    while (index < n || bridge_weight > 0) { //모든 트럭이 다리에 올라갈 때까지 반복 || 다리 위에 남아 있는 트럭이 모두 지나갈 때까지 반복
        bridge_weight -= bridge.front(); // 다리에서 트럭(또는 0) 하나 제거
        bridge.pop();

        // 새로운 트럭을 다리에 올릴 수 있는지 확인
        if (index < n && bridge_weight + trucks[index] <= l) {
            bridge.push(trucks[index]);
            bridge_weight += trucks[index];
            index++;
        } else {
            bridge.push(0); // 트럭을 올릴 수 없으면 0을 넣어 다리 길이 유지
        }
        time++; // 시간 증가
    }
    cout << time << endl; // 결과 출력
    return 0;
    }