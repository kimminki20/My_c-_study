#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
/*
    true를 반환하면 a가 b보다 먼저 오도록(앞에 오도록) 정렬
    false를 반환하면 b가 a보다 먼저 오도록(즉, 뒤로 정렬) 정렬.    
*/
bool cmp(pair<string, int> &a, pair<string, int> &b){
    if (a.second==b.second){ //빈도가 같은 경우
        if (a.first.length()==b.first.length()) //단어의 길이가 같은 경우 
            return a.first < b.first; //사전순(오름차순)으로 정렬
        return a.first.length() > b.first.length(); //단어 길이가 길수록 앞에 배치
    }
    return a.second > b.second; // 빈도수가 높을수록 앞에 배치
}
int main(){
    init();
	int N, M; //N은 단어의 개수,M은 외울 단어의 길이
    cin >> N >> M;
	string str;
	map<string, int> m;
	while (N--){
		cin >> str;
		if (str.size() >= M) // 길이가 M보다 작으면 기록X
			m[str]++;
	}
	vector<pair<string, int>> v(m.begin(), m.end()); //map -> vector로 변환
	sort(v.begin(),v.end(),cmp);
	for (auto& val : v)
		cout << val.first << '\n';
}