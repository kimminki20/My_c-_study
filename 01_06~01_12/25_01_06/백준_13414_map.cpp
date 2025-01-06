//백준 13414 수강신청
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int K, L; //수강신청 가능인원, 대기목록 길이
unordered_map<string, int> app;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second < b.second;  //오름차순으로 정렬
} 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    cin >> K >> L; //수강신청 가능인원, 대기목록 길이
    for(int i = 0; i < L; i++) {
        string str;
        cin >> str;
        app[str] = i; // 학생 이름을 대기목록 순서와 매핑
    }
    
    vector<pair<string, int>> temp; // unordered_map을 vector로 변환하여 정렬
    
    for(auto & a : app) {
        temp.push_back(a);
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for(int i = 0; i < min(K, (int)temp.size()); i++) {
        cout << temp[i].first << "\n";
    }
}