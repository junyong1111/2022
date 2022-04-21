#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    int len = s.length();
    for(int i=0; i<len; i++){
        if(s[i] == ' '){
            answer= answer + ' ';
            continue;
        }
        char tmp = s[i];
        
        
        if(tmp >64 && tmp <91)//대문자
        {
            tmp = tmp + n;
            
            if(tmp>90){
                tmp = tmp -26;
                answer = answer + tmp;
            }
            else{
                answer = answer + tmp;
            }
        }
        
        else if(tmp >96 && tmp <123){ //소문자
           
            if(tmp+n >127){
                tmp = tmp -26;
            } //아스키코드 범위 밖으로 나갔을경우 돌아오는 작업 필요
            tmp = tmp + n; 
            
            if(tmp>122){
                tmp = tmp - 26;
                answer = answer + tmp;
            }
            else{
                answer = answer + tmp;
            }
        }
    }
    return answer;
}