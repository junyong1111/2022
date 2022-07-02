#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct point{
    int x;
    int y;
}Point;

int dx[4] ={-1, 1, 0, 0}; 
int dy[4]= {0, 0, -1, 1};
// 오른쪽 왼쪽 아래 위 

void print(vector<vector<int> >Map, int N, int M){
     for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << Map[i][j] << " ";
        cout << "\n";
    }
}

void Find(vector<vector<int> >&Map, vector<vector<int> >&Distance,  queue<Point> &Search ,int N, int M){
    // x,y 좌표 저장용
    Point P;
    P.x = 0;
    P.y = 0;
    Search.push(P);

    while(!Search.empty()){ // Queue의 원소가 하나라도 있다면 반복 실행

        P.x = Search.front().x;
        P.y = Search.front().y;
        Search.pop();
    
        for(int i=0; i<4; i++){ // 오른쪽 왼쪽 아래 위 
            int new_X = P.x + dx[i];
            int new_Y = P.y + dy[i];

            if( (0 <= new_X  && new_X< M) && (0 <= new_Y && new_Y < N)){
                if( Map[new_Y][new_X] == 1 ){ 
                    // 탐색이 범위안에 있으며 벽이 아닌 경우
                        Point new_P;
                        new_P.x = new_X;
                        new_P.y = new_Y; 
                        Map[new_Y][new_X] = 0; //재탐색을 방지하기 위하여 이미 지나간 좌표는 벽으로 
                        Distance[new_Y][new_X] = Distance[P.y][P.x] +1; //이전 값 +
                        Search.push(new_P); // 탐색 가능한 좌표 갱신
                        
                        
                }       
            }

        } // 네 방향 확인 
    } //while문
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N , M= 0;
    cin >> N >> M;

    vector<vector<int> >Distance(N, vector<int>(M, 0));
    // 최단 방문거리를 확인하기 위하여 생성
    vector<vector<int> >Map(N, vector<int>(M));
    // 현재 가능한 이동가능한 지도 배열 생성

    string Maze;

    for(int i=0; i<N; i++){
        cin >> Maze;
        for(int j=0; j<Maze.length(); j++)
            Map[i][j] = Maze[j]-48;
    }

    // print(Map, N, M);

    queue<Point>Search;    
    Distance[0][0] = 1;
    Map[0][0] = 0;
    //최초 시작 셋팅

    Find(Map, Distance, Search, N, M); //최단거리 함수
    
    // 위 함수가 끝났을 때 Distance 배열에는 각각 좌표마다 최단 거리가 저장되어 있다
    // 만약 Distance 배열의 [N-1][M-1] 값이 0이라면 탐색이 실패한 경우고 값이 저장되어있다면 그 값이 최단거리이다 
    // 현재 문제에서 탐색이 불가능한 경우는 주어지지 않았으므로 그냥 Distance[N-1][M-1]을 출력해도 상관없다.

    // 배열의 인덱스는 0부터 시작이므로 주어진 좌표-1을 해야한다
    if(Distance[N-1][M-1]!=0)
        cout << Distance[N-1][M-1] << "\n";

    return 0;
}