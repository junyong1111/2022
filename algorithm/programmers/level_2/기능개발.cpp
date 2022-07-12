#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int N = progresses.size();
    queue<int>develope;
    
    for(int i=0; i<N; i++){
        int temp = progresses[i];
        int cnt = 0;
        while(temp<100){
            temp += speeds[i];
            cnt++;
        }
        develope.push(cnt);
    } //각 작업당 필요한 시간을 계산하여 큐의 삽입
    
    int temp = 0;
    
    while(!develope.empty()){ //큐의 원소가 있다면
        int answer_cnt = 1; 
        temp = develope.front(); //큐의 제일 앞에 원소를 가져옴
        develope.pop(); // 제거
        
        while(temp >= develope.front() && !develope.empty()){
            // 큐의 원소가 있고 나중 작업이 이미 끝나있다면
            answer_cnt++; //카운터 증가 
            develope.pop(); //삭제
        } //while
        answer.push_back(answer_cnt);
        // 카운터 저장
    }//for
        return answer;
}