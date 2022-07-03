#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Document{
    int Num; //문서의 인덱스
    int imp; //문서의 중요도
}Document;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        Document Docu;
        queue<Document>q;
        // 문서에대한 정보를 저장하는 큐
        priority_queue<int>pq;
        // 문서의 중요도를 저장하는 우선순위 큐

        int cnt = 0;
        int D,T,I = 0;
        cin >> D >> T;
        // 문서의 개수와 목표 문서의 인덱스를 입력받음
        for(int i=0; i<D; i++){
            cin >> Docu.imp ;
            // 문서의 중요도를 입력받아서 구조체에 삽입
            Docu.Num = i;
            q.push(Docu); // 문서의 번호와 중요도를 저장
            pq.push(Docu.imp); //중요도를 우선순위 정렬
        }
    
        while(!q.empty()){ //Queue의 원소가 하나라도 있다면 반복
            int comT = q.front().Num;
            int comI = q.front().imp;
            q.pop();
            // Target인덱스와 중요도 비교를 위해 Queue의 저장된 원소들을 각각 가져오고 제거

            if(pq.top() == comI){ // Queue에 저장된 문서의 중요도와 우선순위 큐에 저장된 중요도를 비교했을때 같은경우 
            // Queue -> [{0,1}, {1,1}, {2,9}, {3,1}, {4,1}, {5,1} ]
            // Pri_Q -> [9, 1, 1, 1, 1, 1 ]   
            // 가장 높은 우선순위(중요도)가 높은 문서는 우선순위 큐에 제일 앞에 위치하고 있다 
            // 결국 가장 중요도가 높은 문서가 나오기 전까지 Queue의 원소는 계속 뒤로 붙고 그게 아니라면 중요도가 높은 순서대로 하나씩 빼주면서 개수를 올려주면 된다.
                pq.pop();
                cnt++;
                if(comT == T){ // 현재 비교하는 인덱스가 Target인덱스인경우 즉 원하는 문서의 위치를 찾은 경우
                    cout << cnt << "\n"; 
                    break;
                }
            }
            else{ // 만약 중요도가 다르다면 현재 꺼낸 원소들을 다시 큐의 맨 뒤로 보내기
                    Docu.Num = comT;
                    Docu.imp = comI;
                    q.push(Docu);
                }
        } 
    }//while

    return 0;
}