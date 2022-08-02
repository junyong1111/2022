#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    vector<int>Answer;
    int answer = 0;
    
    int size = citations.size();
    int max = citations[size-1];
    int idx = 0;
    
    for(int i =1; i<=max; i++){
        // 하나씩 증가하는 i 
        for(int j=idx; j<size; j++){
            if(i <= citations[j]){
                idx = j;
                break;
                // 인용횟수가 조건 이상이라면 인덱스를 기억하고 멈춤
            }
        }
            int Up = size-idx;
            int Dw = size - Up +1;
        // 인용횟수 나머지 계산
            
            if(Up>=i && Dw<=i){
                Answer.push_back(i);
                // 주어진 조건에 맞다면 정답 벡터에 푸쉬
            }
              
    }
    if(Answer.size()==0){return 0;} //예외조건
    sort(Answer.rbegin(), Answer.rend());
    answer = Answer[0];
    // 내림차순으로 정렬 후 최대값 저장
    
    return answer;
}