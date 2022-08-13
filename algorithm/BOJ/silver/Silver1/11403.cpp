#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int>Graph[], int N){
    for(int i=1; i<=N; i++){
        for(vector<int>::iterator it = Graph[i].begin(); it!= Graph[i].end(); it++){
            cout << *it << " ";
        }
        cout << "\n";
    }
} //확인용

void BFS(vector<int>Graph[], vector<vector<int> >&Visit , queue<int>&Q, int Start){
    while(!Q.empty()){
        int idx = Q.front();
        Q.pop();

        for(vector<int>::iterator it = Graph[idx].begin(); it!= Graph[idx].end(); it++){
            if(Visit[Start][*it]==0){
                Visit[Start][*it]=1;
                Q.push(*it);
            }
            
        }
    }
} //BFS탐색 시작

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N =0 ;
    cin >> N;

    vector<int>Graph[N+1];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int temp = 0;
            cin >> temp;
            if(temp == 1)
                Graph[i].push_back(j);
        }
    } // 주어진 조건에 맞게 방향 그래프관계 표현

    vector<vector<int> > Visit(N+1, vector<int>(N+1, 0)); //방문 및 정답 벡터 생성

    for(int i=1; i<=N; i++){
        queue<int>Q;
        Q.push(i);
        BFS(Graph,Visit,Q, i);
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << Visit[i][j] << " ";
        }
        cout <<"\n";
    }

    return 0;
}
