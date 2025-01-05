#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

//각 문자열들을 아스키코드 값과 문자열 해싱으로 생성한 해시값을 활용하여 해시에 저장
//이후 각 문자열들도 해싱한 후 해당 값이 해시에 있으면 true, 아니면 false 반환

long long polynomial_hash(const string& str){ //다항 해수 함수 구현
    const int p = 31; //소수
    const long long m = 1000000007; //버킷의 크기
    long long hash_value = 0;
    
    for(char c : str){
        hash_value = (hash_value * p + c) % m;
    }
    return hash_value;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list){
    unordered_set<long long> hash_set;
    //string_list의 문자열 마다 다항 해시값을 계산하고 저장
    for(const string& str : string_list){
        long long hash = polynomial_hash(str);
        hash_set.insert(hash);
    }
    vector<bool> result;
    for(const string& query : query_list){
        long long query_list = polynomial_hash(query);
        bool found = (hash_set.find(query_hash) != hash_set.end());
        result.push_back(found);
    }
    return result;
}

int main(){
    vector<string> problem = {"apple","banana","cherry"};
    vector<string> solve = {"banana","kiwi","melon","apple"};
    
    vector<bool> results = solution(problem,solve);

    for(int i=0; i<solve.size(); i++){
        cout << "Query: " << solve[i] << " - Result: " << (results[i] ? "Found" : "Not Found") << endl;
    }
    return 0;
}