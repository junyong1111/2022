#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> answer_s ;
    int len = numbers.size();
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(j==len){break;}
            else{
                answer_s.insert(numbers[i] + numbers[j]);
            } //else
        } //for j
    } //for i
    set<int>::iterator it;
    for(it = answer_s.begin(); it!= answer_s.end(); it++ ){
        answer.push_back(*it);
    }
    
    return answer;
}