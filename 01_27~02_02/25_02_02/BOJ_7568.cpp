//백준 7568 덩치
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> v;
     for (int i = 0; i < n; i++) {
        int weight, height;
        cin >> weight >> height;
        v.push_back(make_tuple(i, weight, height));  // 튜플 추가
    }
    // second 값(get<1>())을 기준으로 오름차순 정렬
    sort(v.begin(), v.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<1>(a) < get<1>(b);
    });
    vector<int> result(n);
    int rank = 1,count =0;
    int select_height = get<2>(v[0]); //키를 기준으로 비교하기 시작
    result[get<0>(v[0])] = rank; //이 값은 1로 시작
    for(int i=1; i<n; i++){
        if(select_height < get<2>(v[i])){
            result[get<0>(v[i])] = rank;
            select_height = get<2>(v[i]);
            count++;
        }
        else{
            rank++;
            select_height = get<2>(v[i]);
            result[get<0>(v[i])] = rank+count;
            count = 0;
        }
    }
    for(auto & i : result){
        cout << i << ' ';
    }
}
//왜 2개를 같이 비교해야하는지 모르겠음 일단 풀이는 하긴함.