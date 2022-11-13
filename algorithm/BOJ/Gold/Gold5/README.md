- 1.백준(7576) 토마토
####  너비우선탐색(BFS) 이용하여 정답을 구하는 문제이다
##### <u> 시간초과가 계속 나는 이유를 찾아야 함.</u>

### 시간초과 코드
1. 문제에서 주어진 조건에 맞게 토마토 배열 생성
    - 0 : 익지 않은 토마토
    - 1 : 익은 토마토
    - -1 : 아무것도 없음

2. 좌표 구조체 생성
3. 최단 거리 배열 생성
4. 토마토 배열을 입력받을 때 미리 익은 토마토가 들어있는 좌표를 저장
4. 반복문을 이용하여 토마토가 들어있는 좌표만 BFS실행
5. 만약 반복도중 최소값을 갱신할 수 있다면 최소값 갱신

- 큐의 원소가 있다면 반복
1. 현재 큐의 저장된 좌표를 빼고 pop()
2. 대각선으로 갈 수없으므로 4방향만 체크
    - 현재 좌표에서 4방향으로 갈 수있고 그 좌표가 이동가능한 좌표라면 즉 비어있지 않다면
    - 새로운 좌표를 큐에 삽입
    - 새로운 좌표의 재방문을 피하기 위해 다른값 으로 갱신
    - BFS수행

```c++
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
```

#### 정답 코드 
##### <u> 따로 따로 너비탐색을 하는게 아니라 동시에 진행했어야 한다....</u>

1. 주어진 조건에 맞게 토마토 입력
2. 익은 토마토가 나올때마다 큐에 삽입
3. while반복문을 돌면서 큐에 원소를 빼서 너비탐색 시작
- 예제 3번같은 경우 최초 큐에 [ (0,0) , (2,5) ]가 삽입되어있고
- 1번 BFS탐색 시 (0,0)에서 그래프 탐색을 먼저 하고 그 다음에 큐에 삽입 되기전에 미리 있던 (2,5)좌표가 BFS탐색이 시작된다.
- 따라서 먼저 (0,0) 탐색 그 다음(2,5)에서 탐색이 된다.


- 2.백준(10026) 적록색약
####  너비우선탐색(BFS) 또는 깊이우선탐색(DFS)를 이용하여 정답을 구하는 문제이다
##### <u> 일반인인 경우의 계산이 끝나고 난 후 초록색을 전부 빨강색으로 바꾼 뒤 연산하였는데 답이 나오지 않음</u>

### 실패코드

```c++
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
freopen("input.txt", "r", stdin);

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
        // break;
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
        break;
    }
}
}

cout << notRedGreen << " " <<  RedGreen << "\n";

//    Print(Map, N);
//    print(visit, N);
return 0;
}
```

### 반례 

5
BBBBG
GRBBB
BBBBB
BBBBB
RRRRR

정답: 5 4
출력: 4 3

### 성공 
 
2번째 탐색 때 브레이크를 걸어서 끝까지 탐색이 안된거였다..... 실수하지말자...


- 3.백준(9251) LCS

####  최장공통부분스트링을 찾는 최적화 문제이다
##### <u> 최장 => 최적화 => DP => 점화식 => Working Backward</u>

### 최적화문제는 DP로 해결가능하며 DP를 생각했다면 구조를 파악해서 점화식을 세운다.
### 배우고나면 그닥 어렵지 않은 문제이다.

1. 조건에 맞게 String을 입력받음
2. Memoization을 사용해야 하므로 최대 사이즈의 2차원 배열을 미리 선언
3. 배열의 값을 -1로 초기화
4. str1 또는 str2의 사이즈가 0이 있다면 더 이상 최장부분이 없으므로 0리턴
5. 만약 str1과 str2의 값이 같다면 
    - 2차원배열의 값을 재귀적으로 갱신 후 return
    - 2차원 배열의 대각선의 값 +1
6. 만약 값이 다르다면
    - 2차원배열의 값을 재귀적으로 갱신 후 return
    - 2차원배열의 왼쪽과 위쪽 중 더 Max값으로 값을 갱신

### DP버전 최장길이뿐 아니라 어떠한 문자열인지도 알 수 있음

```c++
#include <iostream>
#define MAX_SIZE 101
#define MAX(a,b) ((a)>(b)?(a):(b))

int L[MAX_SIZE][MAX_SIZE];
int S[MAX_SIZE][MAX_SIZE];

using namespace std;

int Len(char *str);
int LCS_DP(char *str1, char *str2, int M, int N);
void printLCS(char *str1, char *str2,int M, int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" , "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        char str1[MAX_SIZE];
        char str2[MAX_SIZE];
        cin >> str1 >> str2;
        int M = Len(str1);
        int N = Len(str2);
        int answer = LCS_DP(str1,str2,M,N);
        cout << answer << " "; 
        printLCS(str1,str2,M,N);
        cout <<"\n";
    }


    return 0;
}

int Len(char *str){
    int cnt = 0;
    char * temp = str;
    while(*temp!=0){
        cnt++;
        temp++;
    }
    return cnt;
}

int LCS_DP(char *str1, char *str2, int M, int N){
    for(int i=0; i<=M; i++)
        L[i][0] = 0;
    for(int i=0; i<=N; i++)
        L[0][i] = 0;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(str1[i-1] == str2[j-1]){
                L[i][j] = L[i-1][j-1]+1; // 문자가 같으면 대각선 +1
                S[i][j] = 0;
            }
            else{
                L[i][j] = MAX(L[i][j-1], L[i-1][j]);  //다르면 왼쪽 오른쪽 중 큰거
                if(L[i][j] == L[i][j-1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }
    return L[M][N];
}

void printLCS(char *str1, char *str2,int M, int N){
    if(M==0 || N==0)
        return;
    if(S[M][N] ==0){
        printLCS(str1, str2, M-1, N-1);
        cout << str1[M-1];
    }
    else if(S[M][N]==1)
        printLCS(str1, str2, M, N-1);
    else if(S[M][N]==2)
        printLCS(str1, str2, M-1, N);
}
```