#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int mixed_scoville(int a, int b);

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int len = scoville.size();
    bool check = false;
    
    priority_queue<int, vector<int> , greater<int>>pq; //오름차순
    for(int i=0; i<len; i++)
        pq.push(scoville[i]);
    

    while(!pq.empty()){ //pq의 원소가 있다면 
        if(pq.top()>=K){break;} // 오름차순 정렬이므로 제일 처음 숫자가 K이상이면 된다.
        int a = pq.top();
        pq.pop();
        if(pq.empty()){check = true; break;} // 하나만 남았는데 위 조건에서 빠지지 못했다면 답이 없음  
        int b = pq.top();
        pq.pop();
        int c = mixed_scoville(a,b); // 조건에 맞게 연산
        pq.push(c); // 연산한 값을 다시 Push
        answer ++; // 연산의 횟수 추가
    }
    if(check == true){
        return -1;
    }
    
    return answer;
}
int mixed_scoville(int a, int b){
    int temp = a + (b*2);
    return temp ;
}