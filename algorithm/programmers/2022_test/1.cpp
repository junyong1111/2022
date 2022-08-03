#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>


using namespace std;

int solution(vector<int> number) {
    sort(number.begin(), number.end());
    int answer = 0;
    int sum = 0;

//3중 포문으로 하나씩 확인하는 방법
    for(int i=0; i<number.size()-2; i++){
        for(int j= i+1; j<number.size()-1; j++){
            for(int k = j+1; k<number.size(); k++){
                sum = number[i] + number[j] + number[k];
                if(sum == 0){answer ++ ;}
            } //for_k
        } //for_j
    } //for_i 


    


    return answer;
}