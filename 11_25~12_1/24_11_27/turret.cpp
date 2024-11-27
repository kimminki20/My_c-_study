//백준 1002 터렛
#include <iostream>

using namespace std;
int main(){
    int T,x1,x2,y1,y2,r1,r2;
    cin >> T; //테스트 케이스 입력 
    int dst1,dst2,d;
    for(int i=0; i<T; i++){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; //1번 사람 좌표,2번 사람 좌표
    d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); //중심사이 거리 제곱
    dst1 = (r1-r2) * (r1-r2); //반지름의 차의 제곱  
    dst2 = (r1+r2) * (r1+r2); //반지름의 합의 제곱
    if(d == 0){ 
        if(dst1 == 0) //두 중심이 같은 경우 무수히 많은 점
         cout << "-1" << endl;
         else //반지름이 다르며 둘이 만나지않음
         cout << "0" << endl;
    }
    else if(d == dst1 || d == dst2){
        //내접하는 경우 , 외접하는 경우 
        cout << "1" << endl; //원이 한점에서 만나는 경우
    }
    else if(dst1 < d && d < dst2){
        //두 원이 두점에서 만나는 경우
        cout << "2" << endl;
    }
    else  // 두 원이 만나지않는 경우
        cout << "0" << endl;
   
    }
    return 0;
}