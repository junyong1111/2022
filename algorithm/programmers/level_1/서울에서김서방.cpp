#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int find = 0;
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i] == "Kim"){find = i;}
    }
    string str ;
    str = to_string(find);
    answer = answer + "김서방은 " + str +"에 있다";
    return answer;
}