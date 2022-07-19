#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int DAY;
int MAX;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


typedef struct Point{
    int x;
    int y;
}Point;

void print(vector<vector<int> >&Tomato, int N, int M);
void BFS_TOMATO(vector<vector<int> >&Tomato, vector<vector<int> >&Distance ,queue<Point>&Q);
int findAnswer(vector<vector<int> >&Tomato);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r" ,stdin);

    int N,M = 0;
    cin >> M >> N ;
    vector<vector<int> >Tomato(N, vector<int>(M, 0));
    vector<vector<int> >Distance(N, vector<int>(M, 0));
    Point P;
    queue<Point>Q;
    vector<Point>MAP;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin >> Tomato[i][j];
            if(Tomato[i][j] ==1){
                P.x = j;
                P.y = i;
                MAP.push_back(P);
            }
        }

    for(vector<Point>::iterator it = MAP.begin(); it!= MAP.end(); it++){
        P.x = it->x;
        P.y = it->y;
        MAX = 0;
        Q.push(P);
        BFS_TOMATO(Tomato,Distance, Q);
        DAY = DAY+2;
        // print(Distance, N, M);
        // cout <<"\n";
    }
    if(findAnswer(Tomato)){
        return -1;
    };
    cout << MAX << "\n";
    return 0;
}


void print(vector<vector<int> >&Tomato, int N, int M){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << Tomato[i][j] << " ";
        cout << "\n";
    }
} //테스트용

void BFS_TOMATO(vector<vector<int> >&Tomato,vector<vector<int> >&Distance, queue<Point>&Q){
    if(!Q.empty()){
        Point P1;
        P1.x = Q.front().x;
        P1.y = Q.front().y;
        Q.pop();
        int N = Tomato.size();
        int M = Tomato[0].size();

        for(int i=0; i<4; i++){

            // 4방향 탐색
            Point P2;
            P2.x = P1.x + dx[i];
            P2.y = P1.y + dy[i];

            if( (P2.x >=0 && P2.x < M) && (P2.y >=0 && P2.y <N) ){
                // 인덱스 범위안에 있다면
                if(Tomato[P2.y][P2.x]==DAY){ 
                    Tomato[P2.y][P2.x] = DAY+2;
                    if(Distance[P2.y][P2.x]!=0){
                    Distance[P2.y][P2.x] = min(Distance[P1.y][P1.x]+1,Distance[P2.y][P2.x]);
                    }
                    else{
                        Distance[P2.y][P2.x] = Distance[P1.y][P1.x] +1;
                    }
                    if(MAX <=Distance[P2.y][P2.x] ){
                        MAX = Distance[P2.y][P2.x];
                    }
                    Q.push(P2);
                }
            }
            
        }
        BFS_TOMATO(Tomato, Distance, Q);
        
    }
}

int findAnswer(vector<vector<int> >&Tomato){
    int N = Tomato.size();
    int M = Tomato[0].size();

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(Tomato[i][j] ==0)
                return 1;
        
                
    return 0;
}