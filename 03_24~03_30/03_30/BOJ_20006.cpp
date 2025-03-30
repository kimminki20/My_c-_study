// BOJ 20006: 랭킹전 대기열
// 문제 링크: https://www.acmicpc.net/problem/20006
// 문제 설명: 플레이어를 방에 배정하는 문제로, 각 방의 기준 레벨과 플레이어 수를 고려하여 방을 나누는 문제
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M; // N: 플레이어 수, M: 방의 최대 인원 수

vector<pair<int, string>> players; // 플레이어의 레벨과 이름 저장
vector<int> rooms; // 각 방의 기준 레벨 저장
vector<pair<int, string>> games[501]; // 각 방에 있는 플레이어 목록 저장

// 플레이어 이름을 기준으로 오름차순 정렬하는 비교 함수
bool comp(pair<int, string>& a, pair<int, string>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M; // 플레이어 수와 방 최대 인원 수 입력

    // 플레이어 정보 입력받기
    for (int i = 0; i < N; i++) {
        int l;
        string name;
        cin >> l >> name;
        players.push_back({ l, name }); // 벡터에 저장
    }

    // 첫 번째 플레이어를 첫 번째 방에 배정
    rooms.push_back(players[0].first); // 첫 번째 플레이어의 레벨을 방 기준 레벨로 설정
    games[0].push_back(players[0]); // 첫 번째 플레이어를 방에 추가
    
    // 두 번째 플레이어부터 배정 시작
    for (int i = 1; i < N; i++) { 
        int now_Level = players[i].first; // 현재 플레이어의 레벨
        bool flag = true; // 방을 찾았는지 여부
        
        // 기존 방에 들어갈 수 있는지 확인
        for (int j = 0; j < rooms.size(); j++) {
            if (abs(rooms[j] - now_Level) <= 10) { // 레벨 차이가 10 이하인지 확인
                if (games[j].size() < M) { // 방의 정원이 초과되지 않았는지 확인
                    games[j].push_back(players[i]); // 플레이어를 방에 추가
                    flag = false; // 방을 찾았으므로 새 방을 만들 필요 없음
                    break; 
                }
            }
        }
        
        // 기존 방에 들어가지 못하는 경우 새 방 생성
        if (flag) { 
            rooms.push_back(players[i].first); // 새 방의 기준 레벨 설정
            games[rooms.size() - 1].push_back(players[i]); // 새 방에 플레이어 추가
        }
    }

    // 각 방의 정보를 출력
    for (int i = 0; i < rooms.size(); i++) {
        sort(games[i].begin(), games[i].end(), comp); // 플레이어를 이름 기준으로 정렬
        
        if (games[i].size() == M) { // 방이 가득 찼다면
            cout << "Started!" << '\n';
        } else { // 방이 가득 차지 않았다면
            cout << "Waiting!" << '\n';
        }

        // 해당 방에 있는 플레이어 출력
        for (auto a : games[i]) {
            cout << a.first << " " << a.second << '\n';
        }
    }
}