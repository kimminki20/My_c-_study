//백준 1515 수 이어쓰기
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	int answer = 0; //최소값 찾기 변수

	cin >> str; //이어붙인 수 
	int size = str.size();
	int point = 0;

	while (answer++ <= 30000) {
		string tmp = to_string(answer);
    
		for (int i = 0; i < tmp.size(); i++) {
			if (str[point] == tmp[i]) {// 일치하면 pointer증가
				point++;
			}
			if (point == size) { // 마지막을 가리키면 종료
				cout << answer;
				return 0;
			}
		}
	}

	return 0;
}