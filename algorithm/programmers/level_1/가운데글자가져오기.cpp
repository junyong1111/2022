#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    int half = 0;
    if(len%2==0){
        half = len/2;
        answer.push_back(s[half-1]);
        answer.push_back(s[half]);
        
    } // 짝수
    else{
        half = len/2;
        answer.push_back(s[half]);
        
        
    }
    return answer;
}