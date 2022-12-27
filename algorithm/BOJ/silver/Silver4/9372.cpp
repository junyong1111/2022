#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int BFS(vector<int>G[], vector<int>&visit,queue<int> &Q, int cnt);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int country = 0;
        int airplan = 0;
        cin >> country >> airplan;

        vector<int>G[country+1];
        vector<int>visit(country+1, 0);

        for(int i=0; i<airplan; i++){
            int a, b ;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        // 양방향 그래프 연결

        queue<int>Q;
        Q.push(1);
        // 최초 1번 노드 삽입 후 여행시작

        int answer = BFS(G,visit, Q,0);
        cout << answer-1 << "\n";
    }

    return 0;
}

int BFS(vector<int>G[], vector<int>&visit,queue<int> &Q, int cnt)
{
    if(!Q.empty()) // 큐의 원소가 하나라도 있다면
    {
        int temp = Q.front();
        Q.pop();
        cnt++;
        visit[temp] = 1;
        // 원소 제거 후 방문 처리

        for(vector<int>::iterator it = G[temp].begin(); it!= G[temp].end(); it++){
            if(visit[*it]==0){ // 최초 방문
                visit[*it] = 1; //방문 체크
                Q.push(*it); //큐 삽입
                cnt = BFS(G,visit,Q,cnt); //BFS는 바로 진행
            }
        }
    }
    return cnt;
}