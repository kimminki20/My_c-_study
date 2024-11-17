//백준 11650 좌표 정렬하기
#include<iostream>
#include<algorithm>

using namespace std;

struct info{
    int x;
    int y;
};

// 앞에 오는 a보다 뒤에오는 b가 더 크도록, 오름차순 정렬
bool check(info a, info b){
    if(a.x < b.x)
        return true;
    else if (a.x == b.x)
        if (a.y < b.y)
            return true;
    return false;
}

int n;
info arr[100001];

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> arr[i].x >> arr[i].y;
    sort(arr, arr+n, check);

    for(int i=0;i<n;i++)
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    
    return 0;
}
