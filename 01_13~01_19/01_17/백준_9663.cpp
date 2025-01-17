//백준 9663번 N-Queen
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SameRow(int placeRow, int currentRow){
    return placeRow == currentRow;
}//가로줄, 즉 같은 행에 있는지 확인
bool Samediagonal(int placeCol,int placeRow,int currenCol,int currentRow){
    return abs(placeCol - currenCol) == abs(placeRow - currentRow);
}//대각선으로 같은지 확인
bool isSafePosition(const vector<int> &queen,int col,int row){
    for(int i=0; i<col; i++){//해당 열에 놔도 되는지 확인
        if(SameRow(queen[i],row)||Samediagonal(i,queen[i],col,row)){
            return false;
        }//하나라도 문제 있으면 false
    }
    return true; // 문제 없기에 true
}
int placeQueen(vector<int> &queen,int col){
    int n = queen.size();
    if(col == n){
        return 1;
    }
    int count = 0;
    for(int row = 0; row < n; row++){
        if(isSafePosition(queen,col,row)){
            queen[col] = row;
           count += placeQueen(queen,col+1);
            queen[col] = -1;
        }
    }
    return count;
}

int solution(int N){
    vector<int> queen(N,-1);
    return placeQueen(queen,0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cout << solution(N) << endl;
}