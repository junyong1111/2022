#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    int testCase =0 ;
    cin >> testCase;
    

    while(testCase--){
        vector<char>answer; // char 벡터 생성
        vector<char>::iterator iter = answer.begin();
        int it = 0;
        cin >> it; // 2
        string str ; 
        cin >> str; //ABC
        int len = str.length();
        //cout << " str is " << str << " "  << "len is " << len << endl;
        for(int i=0; i<len; i++){ //문자열의 길이만큼 반복
            for(int j=0; j<it; j++){ //주어진 횟수만큼 반복하여 추가
                answer.push_back(str[i]);
            }
        }
        for(iter=answer.begin(); iter!=answer.end(); iter++){
            cout << *iter ; //출력
        }
        cout << endl;      
    }
    return 0;
}