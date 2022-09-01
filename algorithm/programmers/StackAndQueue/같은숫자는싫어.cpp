#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int>S;
    S.push(arr[0]);
    for(auto it = arr.begin()+1; it!= arr.end(); it++){
        if(S.top() != *it){S.push(*it);}
        
    }
    vector<int> answer(S.size(),0);
    for(int i=S.size()-1; i>=0; i--){
        answer[i] = S.top();
        S.pop();
    }
    
    return answer;
}