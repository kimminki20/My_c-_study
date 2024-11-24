//백준 10026 적록색약 첫 골드문제!
//해결 못함. 더 고민할 필요가 있음
#include <iostream>
#include <vector>
using namespace std;

int nomal(vector<char> v,int k){
    int flag1=0,flag2=0,flag3=0,zone=0;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(j>0){
                if(v[i][j] == v[i][j-1] && v[i][j] == 'R')
                    flag1 = 1;
                else if(v[i][j] == v[i][j-1] && v[i][j] == 'B')
                    flag2 = 1;
                else if(v[i][j] == v[i][j-1] && v[i][j] == 'G')
                    flag3 = 1;
            }//0번째 줄인 경우만 해당
            if(i>0){
                if(v[i-1][j]!=v[i][j]){

                }
                else{

                }
            }//여기서부터 위에 값과 비교하면서 값이 다르면 flag값을 1 -> 0이 되게 해야함 이리되면 zone++
            }
            //맨 마지막 줄도 확인해야함.
        }
        return zone;
};//일반인인 경우
int color(vector<char> v,int k){
    int flag1=0,flag2=0,flag3=0,zone=0;


    return zone;
};//색약인 경우
int main(){
    int K = 0;
    vector<char> v;
    cin >> K; //줄의 갯수 K 입력
    for(int i=0; i<K; i++){
        cin >> v[i]; 
    }//구역을 입력함 vector 사용
     /*for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(v[i][j]=='R')
                v[i][j] = '1';
            else if(v[i][j]== 'B')
                v[i][j] = '2';
            else
                v[i][j] = '3';
        }
    }*/
    int a = nomal(v,K),b = color(v,K);
    cout << a << " " << b << endl;
    
}