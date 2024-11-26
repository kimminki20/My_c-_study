#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int x,y;

    Point(int x,int y) : x(x),y(y){}
};

bool compare(const Point &a, const Point &b){
    if(a.x == b.x){
        return a.y < b.y; // x좌표가 같으면  y좌표가 작은 순서대로 정렬
    }
    return a.x < b.x; //x 좌표가 작은 순서대로 정렬
}

int main(){
    vector<Point> points = {{3,4},{1,2},{3,1},{2,5}};

    sort(points.begin(),points.end(),compare); // points 벡터를 사용자 지정으로 정렬
    for(const Point &p : points){
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl; 
    //출력 값 (1,2),(2,5),(3,1),(3,4) 순서로 정렬
    return 0;
}

/* sort() 함수에서 인수를 3개를 받는 경우
    - 시작 반복자, 끝 반복자에 추가로 비교 함수.
    sort함수의 시간 복잡도는 O(NlogN)임.
*/