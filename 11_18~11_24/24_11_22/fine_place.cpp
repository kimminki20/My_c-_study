//백준 1652번 누울 자리를 찾아라
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int k = 0;
    cin >> k;
    int x =0,y=0;
    vector<string> v(k);
    for(int i=0; i<k; i++){
        cin >> v[i];
        } //하나의 행마다 값들을 입력 0행 ~ k-1행까지 넣기
    for(int i=0; i<k; i++){
            int countx = 0, county =0; //새로운 행 열을 할떄마다 0으로 초기화
        for(int j=0; j<k; j++){
            if(v[i][j] == '.')
                countx++;
            else{
                if(countx > 1) x++;
                countx =0;
            }   
            if(v[j][i] == '.')
                county++;
            else{
                if(county > 1) y++;
                county = 0;
            }
        }
       if(countx > 1)
            x++; //행으로 나오는 부분 츨력
        if(county > 1)
            y++; //열로 나오는 부분 출력
    }

    cout << x << " " << y << endl;
    

    }
