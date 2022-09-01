#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Document{
    int Important;
    int Index;
}Document;
// 문서정보를 구조체 선언

int solution(vector<int> priorities, int location) {
    int answer = 1;
    Document D;
    queue<Document>Q;
    
    for(int i=0; i<priorities.size(); i++){
        D.Index = i+1;
        D.Important = priorities[i];
        Q.push(D);
    }
    
    // 주어진 조건에 맞게 큐에 삽입
    
    
    sort(priorities.rbegin(), priorities.rend());
    // 내림차순으로 정렬 
    
    int idx = 0;    
    while(!Q.empty()){
        int temp = Q.front().Important;
        // 큐에 저장된 가장 맨 앞에 있는원소를 가져옴
        
        if(temp == priorities[idx]){
            // 그 값과 원소중 가장 큰값이 같다면 숫자 1증가 ,가장 큰 원소 삭제, 큐 원소 제거
            if(Q.front().Index -1 == location){
                // 그 값이 원하는 타겟 넘버라면 리턴 
                return answer;
            }
            idx++;
            answer++;
            Q.pop();
            
        }
        else{
            // 그게 아니라면 큐에 제일 앞에 있던 원소를 뒤로 보내기
            D.Index = Q.front().Index;
            D.Important = temp;
            Q.pop();
            Q.push(D);
        }
        
    }
    
}