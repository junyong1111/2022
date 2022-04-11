#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int check_p = 0;
    int check_y = 0;
    bool answer = true;
    for(int i=0; i<s.size(); i++){
        if(s[i]== 'p' or s[i] == 'P'){check_p++;}
        else if(s[i]=='y' or s[i] == 'Y'){check_y++;}
        else{continue;}
    }
    if(check_p == check_y){answer = true;}
    else{answer = false;}
    

    return answer;
}