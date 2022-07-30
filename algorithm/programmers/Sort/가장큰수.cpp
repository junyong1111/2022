#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(vector<int> numbers) {
    int size = numbers.size();
    string answer = "";
    int max = 0;
    int index = 0;
    vector<string>str;
    for(auto n : numbers){
        str.push_back(to_string(n));
    }
    
    
    for(int i=0; i<size-1; i++){
        max = str[i][0]; //제일 앞에 있는 원소
        for(int j=i+1; j<size; j++){
            int idx = 1;
            if(max<str[j][0]){
                max = str[j][0];
                index = j;    
            } 
            else if(max ==str[j][0]){
                while(str[i][idx]!=NULL && str[j][idx]!=NULL){
                    if(str[i][idx] == str[j][idx])
                        idx++;
                    else{
                        index = str[i][idx] > str[j][idx]?i:j;
                        break;
                    }
                }
                if(str[i][idx] == NULL){
                    char temp = str[i][idx-1];
                    while(1){
                        if(temp == str[j][idx]){
                            idx++;
                        }
                        else break;
                    }
                    index = temp>str[j][idx]?i:j;
                    
                }else if (str[j][idx] == NULL){
                    char temp = str[j][idx-1];
                    while(1){
                        if(temp == str[i][idx]){
                            idx++;
                        }
                        else break;
                    }
                    index = str[i][idx]>str[j][idx-1]?i:j;
                }
            } // 같은값이 나온 경우   
        }
        answer = answer + str[index];
        swap(str[i], str[index]);
    }
    answer =answer + str[size-1];
    if(answer[0]=='0'){
        answer = "0";
    }    
    // for(auto s: str){
    //     cout << s << " ";
    // }
    
    
    return answer;
}