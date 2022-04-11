#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            answer = answer + "수";
        }
        else{
            answer = answer + "박";
        }
    }
    
    return answer;
}