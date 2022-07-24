#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void DFS(vector<int>Graph[], vector<int>&Visit, stack<int>&S){
    if(!S.empty()){
        int temp = S.top();
        S.pop();
        Visit[temp] = 1;
        for(auto g : Graph[temp]){
            if(Visit[g]==0){
                S.push(g);
                DFS(Graph, Visit, S);
            }
        }
    }
}
// DFS연산

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M ;

    vector<int>Graph[N+1];
    vector<int>Visit(N+1, 0);
    // 재방문을 피하기위한 방문 배열 생성
    int A,B;
    stack<int>S;

    for(int i=0; i<M; i++){    
        cin >> A >> B;
        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }
    // 주어진 조건에 맞게 연결 

    int cnt = 0;

    for(int i=1; i<=N; i++){
        if(Visit[i]==0){
            // 방문된적이 없다면 연산 시작
            S.push(i);
            DFS(Graph, Visit,S);
            cnt ++;
        }   
    }

    cout << cnt << "\n";

    return 0;
}