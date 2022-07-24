#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    bool check = false;
    // 주식 가격이 끝까지 가는지 확인하기 위한 변수
    for(int i=0; i<prices.size(); i++){
        check = false;
        int cnt = 1;
        // 초기 값은 1
        int temp = prices[i];
        // 비교 값 셋팅
        
        
        for(int j=i+1; j<prices.size(); j++){
            if(temp<=prices[j]){
                check = true;
                cnt ++;
            } // 반복을 돌면서 만약에 다음날까지 주식가격이 떨어지지않았으면 갯수 1개 증가
            else{
                // 다음날 주식가격이 떨어졌으면 체크를 false로 바꾸고 여태까지 지나온 일수를 answer에 푸쉬하고 브레이크
                check = false;
                answer.push_back(cnt);
                break;
            }
        }
        if(check == true){
            // 주식가격이 끝가지 간경우  총 요일- 현재 요일로 계산 
            answer.push_back(prices.size()-(i+1));
        }
    }
    // 맨 마지막은 무조건 0이므로
    answer.push_back(0);
    return answer;
}