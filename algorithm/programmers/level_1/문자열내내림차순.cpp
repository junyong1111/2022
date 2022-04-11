#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    sort(s.begin(), s.end() ,greater<>());
    answer = s;
    
    return answer;
    
}