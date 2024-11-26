#include <iostream>
#include <vector>

using namespace std;
/*int main(){
    int a,b,count = 0; //창문수, 사람수
    cin >> a; //창문수 입력받음
    b = a;  // 창문수와 사람 수는 같음
    vector<int> v(a+1,0);
    for(int i=1; i<=a; i++){
        int k = 1;
        while(i*k > a){
            if(v[i*k] == 0){
                v[i*k] = 1;
            }
            else
                v[i*k] = 0;
            k++;
        }
    }
    for(int i=1; i<=a; i++){
        if(v[i]== 1)
            count++;
    }
    cout << count << endl;
} */ //메모리 초과가 나옴.
/*
int main(){
    int a,count=0,k=0;  
    cin >> a;
    vector<int> v(a,0);
    for(int i=0; i<a; i++){
        if(v[i+=k] == 0)
            v[i+=k] = 1;
        else   
            v[i+=k] = 0;
    }
    for(int i=0; i<a; i++){
        if(v[i]== 1)
            count++;
    }
    cout << count << endl;
} */
// 결국 답을 찾아봄 -> 해당 문제는 64MB로 메모리를 설정해 두었기에 창문이 열리고 닫히는 것을 판별하면 무조건 시간초과가 남.
//여기서 중요한 포인트는 창문이 열려 있으려면 무조건 여닫은 횟수가 홀수번 이여야함.
// 이것을 종합적으로 볼 때 대부분의 숫자는 약수의 갯수가 짝수개. 제곱수는 약수의 갯수가 홀수개임
//따라서 제곱수의 갯수에 따라서 창문이 열려 있는 것이 결정.
#include <iostream>

using namespace std;
int main()
{
    int N, count = 0;
    cin >> N;
    
    for(int i = 1; i * i <= N; ++i)
        count++;
    cout << count;
}