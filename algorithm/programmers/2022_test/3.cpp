#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int BFS(vector<int>Graph[], vector<int>&Visit, vector<int>&Dis, queue<int>&Q, int start, int destination);

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    
    vector<int>Graph[n+1];
    // 노드의 연결관계를 나타내 줄 그래프 생성

    int size = roads.size();
    for(int i=0; i<size; i++){
        Graph[roads[i][0]].push_back(roads[i][1]);
        Graph[roads[i][1]].push_back(roads[i][0]);
    }

    // 노드 엣지 연결

    for(int i=0; i<sources.size(); i++){
        vector<int>Visit(n+1, 0);
        vector<int>Dis(n+1, 0);
        queue<int>Q;
    // 주어진 조건에 맞게 BFS 탐색 시작 
        int start = sources[i];
        if(start == destination){answer.push_back(0);}
        else{
        Q.push(start);
        Visit[start] = 1;

        answer.push_back(BFS(Graph, Visit, Dis, Q, start, destination));
        }
    }

    return answer;
}


int BFS(vector<int>Graph[], vector<int>&Visit, vector<int>&Dis, queue<int>&Q, int start, int destination){
    int cnt = 0;

    while(!Q.empty()){
        cnt ++;
        int Point = Q.front();
        Q.pop();

        for(vector<int>::iterator it = Graph[Point].begin(); it!= Graph[Point].end(); it++)
        { // 주어진 노드와 연결된 모든 엣지들을 탐색
            if(Visit[*it]==0){ //최초 방문 노드 
                Visit[*it]=1; // 방문 체크
                Q.push(*it); // 큐에 삽입
                Dis[*it] = Dis[Point]+1; //거리 갱신
                if(*it == destination){return Dis[*it];} //목적지 도달 시 정답 리턴
            }
        }
        
    }
    return -1;
}