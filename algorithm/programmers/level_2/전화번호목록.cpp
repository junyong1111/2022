#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool com(string a, string b){
    return a.length()<b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), com);
    map<string, int>M;
    int size = phone_book[0].length(); //최소 길이 저장
    int idx =0;
    bool check = true; 
    
    
    while(phone_book[idx].length() <= size && idx<phone_book.size())
    {   M.insert(make_pair(phone_book[idx], idx));
        idx++;
    }
    // 최소 길이 만큼 MAP에 인덱스와 함께 저장
    // ex)    ["119", "114", "112", "123223123", "1231231234"] 
    // ->  {"112",0 }, {"114", 1}, {"119", 2}
    
     
    for(int i= idx; i<phone_book.size(); i++){ // 최소길이를 저장한 다음 인덱스부터 확인
        string str = "";
        for(int j=0; j<size; j++)
            str += phone_book[i][j];
        // 최소 길이 부분만큼만 뽑음
        
        if(M.count(str) == 0) // 1번도 들어온적이 없다면 새롭게 인덱스와 함께 추가
            M.insert(make_pair(str, i));
        else{ //이미 똑같은 값이 있는경우 다시 확인해봐야함
            int tmp = M[str];
            int tmp_sz = phone_book[tmp].length();
    // 저장했던 인덱스를 이용하여 탐색 시작 
    // 현재 값과 그전에 저장되어있던 값들을 하나씩 비교해보고 서로 다르다면 멈춤
            for(int k=size; k<tmp_sz; k++){
                if(phone_book[tmp][k] != phone_book[i][k]){
                    check = false;
                    break;
                } // 접두사가 아닌경우
                else check = true; //접두사인 경우
            }
            
            if(check == false)//만약 접두사가 아니라면 그냥 진행
                answer = true;
            else //접두사라면 종료
                return false;   
        }
    }

    return answer;
}