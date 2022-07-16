#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    priority_queue<int, vector<int> , greater<int> >pq;
    //오름차순 우선순위 큐 새성

    int testCase = 0;
    cin >> testCase;
    while(testCase--){
        int Num = 0;
        cin >> Num;
        if(Num!=0)
            pq.push(Num); 
            //0이 아니라면 푸쉬
        else{
            if(pq.empty())
                cout << 0 <<"\n";
                // 0인데 원소가 비어있다면 0 출력
            else{
                cout << pq.top() <<"\n";
                pq.pop();
                // 0이면서 원소가 있다면 제일 작은 값 반환
            }
        }
    }

    return 0;
}