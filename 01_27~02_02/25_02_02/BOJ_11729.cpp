//백준 11729 하노이 탑 이동순서
#include <iostream>

using namespace std;
void func(int a,int b,int n){
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a,6-a-b,n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b,b,n-1);
}
int main(){
    ios_base::sync_with_stdio(fasle);
    cin.tie(0);
    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n';
    func(1,3,k);   
}