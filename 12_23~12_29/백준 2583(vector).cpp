#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int arr[101][101];
// 상하좌우 세팅
int dirX[] = { 0, 0, -1, 1 };
int dirY[] = { -1, 1, 0, 0 };
int cnt = 0;
vector<int> result;

int dfs(int y, int x){
    // 방문처리
	arr[y][x] = 1;
    //count +1 증가
	cnt++;
    // 상하좌우 탐색
	for (int i = 0; i < 4; i++){
		int new_y = y + dirY[i];
		int new_x = x + dirX[i];
        // 탐색할 수 있는 좌표라면
		if (new_y >= 0 && new_y < m && new_x >= 0 && new_x < n)
		{ 
           // 빈칸이라면(연결할 수 있기 때문에 재귀를 통한 탐색)
			if (arr[new_y][new_x] == 0)
				dfs(new_y,new_x);
		}
	}
    // 개수 반환
	return cnt;
}

int main(){
    // 세로, 가로 직사각형 개수
	cin >> m >> n >> k;
	int x1, x2, y1, y2;
	for (int i = 0; i < k; i++)
	{
       // 왼쪽 아래 꼭짓점과 오른쪽 위 꼭짓점 입력
		cin >> x1 >> y1 >> x2 >> y2;
        // 꼭짓점을 통해 직사각형 칸 칠하기
		for (int y = y1; y < y2; y++){
			for (int x = x1; x < x2; x++){
                // 직사각형의 포함되는 칸을 1로 바꿈
				arr[y][x] = 1;
			}
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
            // 빈칸(0)이라면
			if (arr[i][j] == 0)
			{	
                // DFS를 통해 센 개수를 result Vector에 저장
				result.push_back(dfs(i, j));
                // 개수 초기화
				cnt = 0;
			}
		}
	}
    // 오름차순 정렬
	sort(result.begin(), result.end());
    // 나누어지는 영역의 개수 출력
	cout << result.size() << endl;
    // 정렬된 각 영역의 넓이 출력
	for (int i = 0; i < result.size(); i++){
        	cout << result[i] << ' ';
	}
}