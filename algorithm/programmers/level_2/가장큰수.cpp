#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool com(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>Answer;
    
    for(auto number : numbers)
        Answer.push_back(to_string(number));
    
    sort(Answer.begin(), Answer.end(), com);
    
    for(auto A : Answer)
        answer = answer + A;
    
    if(answer[0] == '0') {return "0";}
    return answer;
}