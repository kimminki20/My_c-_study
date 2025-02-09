//백준 2669 직사각형 네개의 합집합의 면적 구하기
#include <iostream>
using namespace std;

int main(){
    int input = 4;
    int x1,y1,x2,y2;
    bool arr[101][101];
    while(input--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i= y1; i <=y2; i++){
            for(int j=x1; j<=x2; j++){
                arr[y1][x1] = true;
            }
        }
    }
    int count = 0;
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(arr[i][j] == true) count++;
        }
    }
    cout << count;
}