#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max = 0;
    int min = 0;
    int C_Z = 0;
    int C_C = 0;
    for(int i=0 ;i< lottos.size(); i++){
        if(lottos[i]==0){C_Z++;}
    } // 0 체크
    for(int i=0; i<lottos.size(); i++){
        for(int j=0; j<win_nums.size(); j++){
            if(lottos[i] == win_nums[j]){C_C++;}
        } // 당첨갯수 체크
    }
    //cout << "C_Z :" << C_Z << " " << "C_C:" << C_C <<endl;
    max = C_Z + C_C ;
    min = C_C;
    switch(max){
        case 6:
            answer.push_back(1); 
            break;
        case 5:
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5);
            break;
        default:
            answer.push_back(6);
            break;
                      
    }//switch문
    switch(min){
        case 6:
            answer.push_back(1); 
            break;
        case 5:
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5);
            break;
        default:
            answer.push_back(6);
            break;
                      
    }//switch문
    
    return answer;
}
