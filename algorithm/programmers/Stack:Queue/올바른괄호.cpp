#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int len = s.length();
    stack<char>S;
    for(int i=0; i<len; i++){
        if(s[i] =='(')
            S.push(s[i]);
        
        else if(s[i] == ')'){
            if(S.empty()){answer = false; return answer;}
            S.pop();
        }
    }//for
    
    if(!S.empty())
        answer = false;
    
    return answer;
}