#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void Print(vector<vector<string> >&Map, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << Map[i][j] << " ";
        }
        cout <<"\n";
    }
}

void print(vector<vector<int> >&Map, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << Map[i][j] << " ";
        }
        cout <<"\n";
    }
}

void init(vector<vector<int> >&visit){
    for(int i=0; i<visit.size(); i++){
        for(int j=0; j<visit.size(); j++){
            visit[i][j] = 0;
        }
    }
}

void Init(vector<vector<string> >&map){
    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map.size(); j++){
            if(map[i][j] == "G"){
                map[i][j] = "R";
            }
        }
    }
}

typedef struct Point{
    int x;
    int y;
}point;

void BFS(vector<vector<string> >&Map, vector<vector<int> >&visit, queue<point>&Q, string s){
    while(!Q.empty()){
        point P;
        int N = Map.size();
        P.x = Q.front().x;
        P.y = Q.front().y;
        Q.pop();

        for(int i=0; i<4; i++){
            point new_point;
            new_point.x = P.x + dx[i];
            new_point.y = P.y + dy[i];

            if( (new_point.x>=0 && new_point.x<N) && (new_point.y>=0 && new_point.y<N)){
                if(visit[new_point.y][new_point.x] ==0 && Map[new_point.y][new_point.x] == s){
                    visit[new_point.y][new_point.x]=1;
                    Q.push(new_point);
                }
            }
        }

    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N = 0;
    cin >> N;

    vector<vector<string> >Map(N, vector<string>(N));
    vector<vector<int> >visit(N, vector<int>(N,0));

   for(int i =0; i<N; i++){
    string str;
    cin >> str;

    for(int j=0; j<str.length(); j++)
        Map[i][j] = str[j];
   }

   queue<point>Q;
   point p ;
   string s;

   int notRedGreen = 0;
   int RedGreen = 0;
   for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
        if(visit[i][j]==0){
            visit[i][j] = 1;
            p.x = j;
            p.y = i;
            s = Map[i][j];
            Q.push(p);
            BFS(Map,visit, Q,s);
            notRedGreen ++;
        }
    }
   }


init(visit);
Init(Map);

   for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
        if(visit[i][j]==0){
            visit[i][j] = 1;
            p.x = j;
            p.y = i;
            s = Map[i][j];
            Q.push(p);
            BFS(Map,visit, Q,s);
            RedGreen ++;
        }
    }
   }

   cout << notRedGreen << " " <<  RedGreen << "\n";

//    Print(Map, N);
//    print(visit, N);
    return 0;
}