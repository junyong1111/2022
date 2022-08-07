#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int>M;
    
    for(int i=0; i<clothes.size(); i++){
        if(M.count(clothes[i][1]) == 0) 
            M.insert(make_pair(clothes[i][1], 1) );
        else
            M[clothes[i][1]] ++; 
    }
    // 종류별로 갯수를 확인함
    
    for(auto m : M){
        answer = answer * (m.second+1);
    } //자기 자신도 포함이므로 +1 
    answer = answer -1; //아무런 옷도 입지않은 상태는 빼준다.

    return answer;
}