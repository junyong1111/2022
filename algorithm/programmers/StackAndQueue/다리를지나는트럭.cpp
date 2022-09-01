#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int>wait;
    queue<int>passing;
    int len = bridge_length;
    
    for(int i=0; i<len; i++)
        passing.push(0);
    // 주어진 다리 길이에 맞게 최초 0을 삽입한 큐 생성
    
    for(auto t : truck_weights)
        wait.push(t);
    
    // 트럭 정보 입력
    
   
    
    int answer = 0;
    int W = 0;
    int temp = 0;
    // 정답과 현재 다리의 총 무게, 건너야하는 트럭 정보 변수 선언 
    
    while(!wait.empty()){ //대기 트럭이 있는동안 반복
        answer ++;
        // 1초가 지나고 
        
        temp = wait.front();    //대기 트럭 정보 저장  
        W = W-passing.front();   // 다리를 건넌 트럭은 무게에서 제외 
        passing.pop(); // 다리에 제일 선두에 있는 트럭 제거
        
        if( W + temp  <= weight){ // 현재 다리 총 무게 + 대기 트럭이 건널 수 있으면 
            W = W+temp; wait.pop();  // 대기 트럭 다리에 올리고 
            passing.push(temp); //한 칸 전진
        }
        else{
            passing.push(0); // 만약 대기 트럭을 못 올린다면 0으로 채움 
        }
    } //while
    
    answer = answer + bridge_length; //마지막 트럭만 보내면 끝임
        
    
    return answer;
}