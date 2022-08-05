#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool com(string a, string b){
    return a.length()<b.length();
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), com);
    
    string temp;
    
    for(int i=0; i<phone_book.size(); i++){
        temp = phone_book[i];
        bool check = false;
        
        int len = temp.length();
        for(int j= i+1; j<phone_book.size(); j++){
            for(int k=0; k<len; k++){
                if(temp[k] == phone_book[j][k])
                    check = true;
                else{
                    check = false;
                    break;
                } 
            }
            if(check == true){
                return false;
            }
            
        }
    }
    answer = true ;
    
    return answer;
}