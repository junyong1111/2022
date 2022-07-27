//실패 코드 ... 뭐가 잘못된걸까

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    int len = bridge_length;
    
    
    
    for(int i=0; i<truck_weights.size()-1; i++){
        int temp = truck_weights[i] + truck_weights[i+1];
        if(temp <= weight){
            answer ++;
        }
        else{
            answer = answer + len;
        }
    }
    
    answer = answer + len;
    
    
    return answer;
}