#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// 노드의 인접간선들을 연결해주는 함수
void IncidentEdge(vector<int> Graph[], int N)
{
    int V1 = 0;
    int V2 = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> V1 >> V2;
        Graph[V1].push_back(V2);
        Graph[V2].push_back(V1);
    }
}

// 연결관계를 오름차순으로 정렬
void SortGraph(vector<int> Graph[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        stable_sort(Graph[i].begin(), Graph[i].end());
    }
}

// 방문배열 초기화
void init(vector<int> &V, int N)
{
    for (int i = 1; i <= N; i++)
        V[i] = 0;
}

void print(vector<int> Graph[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        cout << i << "-->";
        for (vector<int>::iterator it = Graph[i].begin(); it != Graph[i].end(); it++)
        {
            cout << *it << "-->";
        }
        cout << "\n";
    }
}

void DFS(vector<int> Graph[], vector<int> &Visit, int Start, stack<int> &S)
{
    if (!S.empty()) // 스택의 원소가 하나라도 있다면 실행
    {
        cout << S.top() << " ";
        Visit[Start] = 1;
        S.pop(); //출력 이후 방문 체크하고 원소 제거
        for (vector<int>::iterator it = Graph[Start].begin(); it != Graph[Start].end(); it++)
        {                        // 출발 노드의 인접노드 탐색
            if (Visit[*it] == 0) //방문기록이 없다면
            {
                S.push(*it);               //해당 원소를 스택에 삽입
                DFS(Graph, Visit, *it, S); // 해당 원소를 기준으로 다시 DFS실행
            }
        }
    }
}

void BFS(vector<int> Graph[], vector<int> &Visit, int Start, queue<int> &Q)
{
    if (!Q.empty()) //큐의 원소가 하나라도 있다면 실행
    {
        if (Visit[Start] != 1)        //방문기록이 없다면
            cout << Q.front() << " "; //출력
        Visit[Start] = 1;
        Q.pop(); //방문체크 후 제거
        for (vector<int>::iterator it = Graph[Start].begin(); it != Graph[Start].end(); it++)
        {                        //출발 노드의 모든 인접 노드를 탐색
            if (Visit[*it] == 0) //방문 기록이 없다면 전부 큐에 삽입
                Q.push(*it);
        }
        BFS(Graph, Visit, Q.front(), Q); //모든 원소를 삽입 한 후 큐의 front를 기준으로 다시 BFS실행
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Vertical = 0;
    int Edge = 0;
    int Start = 0;
    cin >> Vertical >> Edge >> Start;

    //시작 노드의 Index를 1로 고정하기 위해 +1
    vector<int> Visit(Vertical + 1, 0);
    vector<int> Graph[Vertical + 1];

    IncidentEdge(Graph, Edge);
    SortGraph(Graph, Vertical);

    stack<int> S;
    S.push(Start);
    DFS(Graph, Visit, Start, S);
    cout << "\n";
    //// 출발 노드를 스택에 넣어준 후 DFS 실행 ///

    init(Visit, Vertical);

    queue<int> Q;
    Q.push(Start);
    BFS(Graph, Visit, Start, Q);
    cout << "\n";
    //// 출발 노드를 큐에 넣어준 후 BFS 실행 ///

    return 0;
}
