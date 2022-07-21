#include <iostream>
#include <queue>

using namespace std;

int N;
int K;
int FLAG;
vector<int>Visit(100001,0);
queue<int>Q;
int dpoint[2] = {-1,1};
void BFS();


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    int n, k= 0;    
    cin >> n  >> k;
    N = n;
    K = k;

    Q.push(N);
    Visit[N] = 1;
    FLAG = false;

    BFS();
    cout << Visit[k]-1<<"\n";

    // cout << "ANSWER IS " << Visit[k]-1 <<"\n";
    return 0;
}

void BFS(){
    while(!Q.empty()){
        int Point;
        int point = Q.front();
        
        Q.pop();

        for(int i=0; i<3; i++){
            if(i==2)
                Point = point * 2;
            else{Point = point + dpoint[i];}
            
            if(Point>=0 && Point <100001){
                if(Visit[Point]==0){
                    Visit[Point] = Visit[point]+1;
                    if(Point==K){FLAG = true; break;}
                    // 원하는 목적지까지 탐색이 완료되었으면 플래그를 true로 바꾸고 종료
                    Q.push(Point); 
                }
            }
        }
        if(FLAG == true){break;}
    }
}