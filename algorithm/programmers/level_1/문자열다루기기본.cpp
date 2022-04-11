#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    int cnt = 0;
    for(int i=0; i<len; i++){
        switch(s[i]){
            case '0': 
                cnt ++;
                break;
            case '1': 
                cnt ++;
                break;
            case '2': 
                cnt ++;
                break;
            case '3': 
                cnt ++;
                break;
            case '4': 
                cnt ++;
                break;
            case '5': 
                cnt ++;
                break;
            case '6': 
                cnt ++;
                break;
            case '7': 
                cnt ++;
                break;
            case '8': 
                cnt ++;
                break;
            case '9': 
                cnt ++;
                break;
            default :
                answer = false;
                return answer;
        }
        if(cnt==4 || cnt==6){
            answer = true;
        }
        else answer = false;
    }
    return answer;
}