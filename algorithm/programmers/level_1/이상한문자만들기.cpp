#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    int i =0;
    int cnt = 0;
    while(len--)
    {
        if(s[i] == ' '){
            cnt = 0;
            i++;
        }
        else{
            
        
        if(cnt %2 ==0){
            s[i] = toupper(s[i]);  
        }
        else{
            s[i] = tolower(s[i]);
        }
        
        i++;
        cnt ++;
        }
    }
    answer = s;
    cout << answer;
    return answer;
}