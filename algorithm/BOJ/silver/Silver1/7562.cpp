#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Point{
    int x;
    int y;
}point;

void Bfs(vector<vector<int> >&map,vector<vector<int> >&visit, queue<point>&q , point &targetPoint);
void CheckVector(vector<vector<int> >&v, int size);

int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int N = 0;
        point p;
        point targetPoint;
        cin >> N;
        vector<vector<int> >map(N,vector<int>(N,0));
        vector<vector<int> >visit(N,vector<int>(N,0));
        cin >> p.y >> p.x;
        cin >> targetPoint.y >> targetPoint.x;
        if ((p.y == targetPoint.y) && (p.x == targetPoint.x)){
            cout << 0 <<"\n";
        }
        else{
            visit[p.y][p.x] = 1;
            queue<point>q;
            q.push(p);
            Bfs(map,visit,q, targetPoint);
            // CheckVector(map, map.size());
            
            if(map[targetPoint.y][targetPoint.x]!=0){
                cout << map[targetPoint.y][targetPoint.x] <<"\n";
            }
        }
    
    }

    return 0;
}
void Bfs(vector<vector<int> >&map,vector<vector<int> >&visit, queue<point>&q , point &targetPoint){
    if(!q.empty()){
        int size = map.size();
        point p;
        p.x = q.front().x; 
        p.y = q.front().y;
        q.pop();
        
        for(int i=0; i<8; i++){
            point P;
            P.y = dy[i] + p.y;
            P.x = dx[i] + p.x;

            if((P.y>=0 && P.y<size) && (P.x>=0 && P.x <size)){ //index 범위안에 존재
                if(visit[P.y][P.x]==0){ //최초 방문
                    visit[P.y][P.x] = 1;
                    map[P.y][P.x] = map[p.y][p.x]+1;
                    if((P.y == targetPoint.y) && (P.x == targetPoint.x)){
                        return ;
                    }
                    q.push(P);
                    
                }                
            }
        }
        Bfs(map,visit,q,targetPoint);
        
    }

}
void CheckVector(vector<vector<int> >&v, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << v[i][j] <<" ";
        }
        cout <<"\n";
    }
}