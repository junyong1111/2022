#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Point{
    int x;
    int y;
}point;

int dx[8] = {0,1,-1,0,1,1,-1,-1};
int dy[8] = {1,0,0,-1,-1,1,1,-1};

void Init(vector<vector<int> >&map, int x, int y);
void CheckVector(vector<vector<int> >&V, int x, int y);
void BFS(vector<vector<int> >&map,vector<vector<int> >&visit, queue<point>&q);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);
    //1 Land
    //0 Sea

    int x = 0;
    int y = 0;
    cin >> x >> y ;
    while(x!=0 && y!=0){
        
        vector<vector<int> >map(y,vector<int>(x,0));
        vector<vector<int> >visit(y,vector<int>(x,0));
        queue<point>q;
        point p;
        Init(map,x,y);
        
        int cnt = 0;
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(visit[i][j]==0 && map[i][j] ==1){
                    p.x = j;
                    p.y = i;
                    visit[p.y][p.x] = 1;
                    q.push(p);
                    BFS(map,visit,q);
                    cnt++;
                }
            }
        }
        cout  << cnt <<"\n";
        cin >> x >> y ;
    }


    return 0;
}

void Init(vector<vector<int> >&map, int x, int y){
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            cin >> map[i][j];
        }
    }
}

void CheckVector(vector<vector<int> >&V, int x, int y){
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            cout << V[i][j] <<" ";
        }
        cout << "\n";
    }
}

void BFS(vector<vector<int> >&map,vector<vector<int> >&visit, queue<point>&q){
    if(!q.empty()){
        int x = map[0].size();
        int y = map.size();

        point p;
        p.x = q.front().x;
        p.y = q.front().y;
        q.pop();

        for(int i=0; i<8; i++){
            point P;
            P.x = dx[i] + p.x;
            P.y = dy[i] + p.y;

            if((P.x>=0 && P.x<x) && (P.y>=0 && P.y<y)){
                if(visit[P.y][P.x]==0 && map[P.y][P.x] ==1){
                    visit[P.y][P.x] = 1;
                    q.push(P);
                }
            }
        }
        BFS(map,visit,q);
    }
}