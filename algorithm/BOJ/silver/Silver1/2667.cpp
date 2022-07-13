#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct Dic{
    int Number;
    int Count;
}Dic;
// 단지의 정보를 저장할 구조체 선언
typedef struct Point{
    int x;
    int y;
}Point;
// 단지의 좌표를 저장할 구조체 선언

void Print(vector<vector<int> >&map, int n);
int makeBuildings(vector<vector<int> >&map, stack<Point>&s, int i, int j, int cnt);
bool com(Dic a, Dic b);
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt" , "r", stdin);
    int N= 0;
    cin >> N;
    vector<vector<int> >map(N, vector<int>(N, 0));
    for(int i=0; i<N; i++){
        string str;
        cin >> str; 
        for(int j=0; j<str.length(); j++)
            map[i][j] = str[j]-48;
    }
    // 주어진 조건에 맞게 Map배열의 삽입
    // Print(map,N);


    vector<Dic>answer;
    stack<Point>s;
    Dic d;
    Point p;
    int dange = 1;
    int cnt = 0; //집 갯수를 저장할 변수

    for(int i=0; i<N; i++){ //모든 Map을 방문
        for(int j=0; j<N; j++){
            if(map[i][j] ==1){ //만약 빈 집이아니라면
                cnt = 0;
                p.x = j;
                p.y = i;
                s.push(p); //현재 좌표를 스택의 push 
                d.Count = makeBuildings(map,s, i,j,cnt); //DFS연산 시작
                d.Number = dange++;
                answer.push_back(d); //카운터 값 저장
            }
        }
    }

    stable_sort(answer.begin(), answer.end(), com);
    // 오름차순 정렬

    cout <<  answer.size() << "\n";
    for(vector<Dic>::iterator it = answer.begin(); it!= answer.end(); it++)
        cout << it->Count << "\n"; 

    return 0;
}


bool com(Dic a, Dic b){
    return a.Count < b.Count;
} //단지의 갯수로 오름차순 정렬

void Print(vector<vector<int> >&map, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << map[i][j] <<" ";
        cout << "\n";
    }
} //확인용

int makeBuildings(vector<vector<int> >&map, stack<Point>&s, int i, int j, int cnt){
    if(!s.empty()){
        Point p;
        p.x = s.top().x;
        p.y = s.top().y;
        s.pop();
        map[p.y][p.x] = 0;
        cnt ++;
        int size = map.size();

        for(int k=0; k<4; k++){
            Point NP;
            NP.x = p.x+dx[k];
            NP.y = p.y+dy[k];

            if((NP.x>=0 && NP.x<size) && (NP.y>=0 && NP.y<size)){
                if(map[NP.y][NP.x] == 1){
                    map[NP.y][NP.x] = 0;
                    s.push(NP);
                    cnt = makeBuildings(map,s,NP.y,NP.x, cnt);
                }
            }
        }
    }
    return cnt;
}
