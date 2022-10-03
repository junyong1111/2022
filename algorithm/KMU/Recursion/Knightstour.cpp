#include <iostream>

using namespace std;

typedef struct Point{
    int x;
    int y;
}point;

int knightstour(int *Knight, int *Visit, int N, int M, point p, int cnt) ;
void init(int *Arr, int N, int M);
void check_arr(int *Visit, int N, int M);

int dy[8] = {-2,-1 ,1, 2,2,1,-1,-2};
int dx[8] = {1,2,2, 1,-1,-2,-2,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int N,M;
        point p;
        cin >> N >> M >> p.y >> p.x;

        int Knight[N][M];
        int Visit[N][M];
        init((int *)Knight, N,M);
        init((int *)Visit, N,M);

        p.y --;
        p.x--;
        Visit[p.y][p.x] = 1;
        Knight[p.y][p.x] = 1;
        if(knightstour((int *)Knight, (int *)Visit, N, M, p,1)){
            cout << 1<< "\n";
            check_arr((int *)Knight,N,M);
        }
        else{
            cout << 0 << "\n";
        }

    }

    return 0;   
}

void init(int *Arr, int N, int M){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            *(Arr + i*M +j) = 0;
        }
    }
}

void check_arr(int *Visit, int N, int M){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << *(Visit + i*M +j)  << " ";
        }
        cout <<"\n";
    }
}

int knightstour(int *Knight, int *Visit, int N, int M, point p, int cnt) {
    if (cnt == N*M){
        return 1;
    }
    for(int i=0; i<8; i++){
       point P;
       P.x = p.x+dx[i];
       P.y = p.y+dy[i];
       if( (P.x>=0 && P.x<M) && (P.y>=0 && P.y<N)){// 체스판 범위를 벗어나지 않는다면
            if(*(Visit+ P.y*M +P.x)!=1){ //최초 방문의 경우
                *(Visit+ P.y*M +P.x)=1; // 방문체크
                *(Knight+ P.y*M +P.x)=cnt+1; //방문 순서 체크
                if( knightstour((int *)Knight, (int *)Visit, N, M, P,cnt+1))
                    return 1; 
                *(Visit+ P.y*M +P.x)=0;
                
            }
       }    
    }
    return 0;

}