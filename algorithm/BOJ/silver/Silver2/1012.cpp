#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

typedef struct Point{
    int X;
    int Y;
}Point;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0,-1, 1};

void print(vector<vector<int> >&Farm, int Y, int X);
void Youginong(vector<vector<int> >&Farm, queue<Point>&Q);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    vector<int>answer;

    while(testCase--){ // TestCase 반복
    int Y, X, Num = 0;
    cin >> X >> Y >> Num;
    vector<vector<int> >Farm(Y, vector<int>(X, 0) );
    Point P;
    for(int i=0; i<Num; i++){
        cin >> P.X >> P.Y;
        Farm[P.Y][P.X] = 1;
    }
    int cnt = 0;
    queue<Point>Q;

    // 주어진 값에 맞게 입력
   
    for(int i=0; i<Y; i++)
        for(int j=0; j<X; j++)
            if(Farm[i][j]!=0){
                P.X = j;
                P.Y = i;
                Q.push(P);
                Youginong(Farm, Q);
                cnt ++;
                // 탐색이 끝날 때 마다 카운터 1증가
            }
    answer.push_back(cnt);   
    } // Testcase while문

    for(vector<int>::iterator it = answer.begin(); it!= answer.end(); it++)
        cout << *it << "\n";
    return 0;
}

void print(vector<vector<int> >&Farm, int Y, int X){
     for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++)
            cout << Farm[i][j] <<" ";
        cout << "\n";
    }
}

void Youginong(vector<vector<int> >&Farm, queue<Point>&Q){
    if(!Q.empty()){
        int Y_size = Farm.size();
        int X_size = Farm[0].size();
        Point P1;
        P1.X = Q.front().X;
        P1.Y = Q.front().Y;
        Q.pop();

        for(int i=0; i<4; i++){
            Point P2;
            P2.X = P1.X + dx[i];
            P2.Y = P1.Y + dy[i];
            if( (P2.X >=0 &&P2.X <X_size) && (P2.Y>=0 && P2.Y <Y_size)){
                if(Farm[P2.Y][P2.X] == 1){
                    Farm[P2.Y][P2.X] = 0;
                    Q.push(P2);
                    Youginong(Farm, Q);
                } // 배추라면 
            } //범위 내 존재
        }
        
    }
}