#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int> >Box(1001, vector<int>(1001, 0));
// 토마토 박스정보
queue<pair<int, int> >Q;


int dx[4] = {-1,1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// 4방향 탐색

int N;
int M;
int MAX;

void BFS(){
    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        // 좌표 삽입

        for(int i=0; i<4; i++){
            // 4방향 탐색
            int X = x + dx[i];
            int Y = y + dy[i];

            if((X>=0 && X<M) && (Y>=0 && Y<N)){
                if(Box[Y][X] ==0){
                    // 인덱스 범위 내에 있고 익지않은 토마토라면
                    Box[Y][X] = Box[y][x] +1;
                    // 하나씩 증가
                    Q.push(make_pair(Y,X));
                }
            }
        }
    }
}

int findAnswer(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(Box[i][j] ==0 )
            // 익지않은 토마토가 하나라도 있다면 답없음
                return 1;
            if(MAX < Box[i][j]){
                MAX = Box[i][j];
            }
            // 맥스값 갱신
        }
    }
    return 0;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    
    int n,m = 0;
    cin >> m >> n;

    N = n;
    M = m;

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
        int temp = 0;
        cin >> temp ;
        // 익은 토마토가 나온다면 큐에 삽입
        if(temp==1)
            Q.push(make_pair(i,j)); //y먼저 삽입
        Box[i][j] = temp;
    }
  }
BFS();
// BFS탐색 시작

if(findAnswer())
    cout << -1 <<"\n";

else
    cout << MAX-1 <<"\n";

    return 0;
}