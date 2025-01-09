#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant,vector<string> completion){
    sort(participant.begin(),participant.end()); //정렬해버림
    sort(completion.begin(),completion.end()); //정렬해버림
    for(int i=0; i< completion.size(); i++){ 
        if(participant[i] != completion[i]){ //같지않은 것이 나오면 리턴
            return participant[i];
        }
    }
    return participant[participant.size()-1]; //for문이 끝나면 size에서 맨 뒤에꺼 리턴.
}