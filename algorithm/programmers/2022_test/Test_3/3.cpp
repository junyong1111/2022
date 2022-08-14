#include <string>
#include <vector>
#include <queue>

using namespace std;

int Answer;

void BFS(vector<int>Graph[], vector<int>&Visit,queue<int>&Q){
    while(!Q.empty()){
        bool check = false;
        int temp = Q.front();
        Visit[temp] = 1;
        Q.pop();

        for(vector<int>::iterator it = Graph[temp].begin(); it!= Graph[temp].end(); it++){
            if(Visit[*it]==0){
                Visit[*it] = 1;
                Q.push(*it);
                check = true;
            }
            else check = false;
        }
        if(check == true){check = false; Answer++; }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    Answer = answer;
    vector<int>Graph[n+1];
    vector<int>Visit(n+1,0);

    for(int i=0; i<lighthouse.size(); i++){
        int A = lighthouse[i][0];
        int B = lighthouse[i][1];

        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }

    for(int i=1; i<=n; i++){
        queue<int>Q;
        if(Visit[i] == 0){
            Q.push(i);
            BFS(Graph,Visit,Q);
        }
    }
    
    // printf("%d" , Answer);

    return Answer;
}