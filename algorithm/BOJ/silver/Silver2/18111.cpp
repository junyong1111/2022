#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define INF 210000000

using namespace std;

int find_min_time( vector<vector<int> >&map, int level , int N, int M, int B);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    int N, M, B ;
    cin >> N >> M >> B;

    int max = 0;
    int min = INF;

    vector<vector<int> >map(N, vector<int>(M, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] >= max)
                max = map[i][j];
            if(map[i][j] <= min)
                min = map[i][j];
        }
    }
    
    int min_time = INF;
    int Level = 0 ;
    int time = 0;

    for(int i = min; i<= max; i++){
        time = find_min_time(map,i,N,M,B);
        if(time >=0 && time <= min_time){
            min_time = time;
            Level = i;
        }
    }//MAX~MIN
    cout << min_time <<" " << Level <<"\n";
    return 0;
}

int find_min_time(vector<vector<int> >&map, int level ,int N, int M, int B){
    int temp = 0;
    int block = 0;
    int time = 0;
    int neededBlock = 0;


    for(int i = 0; i<N; i++){
        for(int j=0; j<M; j++){
            temp = map[i][j] - level;
            if(temp>0){ //만약 temp가 양수라면 현재 level를 기준으로 땅 고르기 했을 때 블록을 빼야함
                block = block+temp; //제거는 2초가 걸리며 제거한 블록을 인벤토리에 넣어야 함
                // time += 2*temp;
            } //if_양수
            else if(temp<0){ //  현재 level을 만들기 위해서 블록을 더 올려야 하는경우
                neededBlock = neededBlock+abs(temp); //올리기위해 필요한 블록 수를 지정
                // time +=abs(temp);
            } //if_양수 제외 else
        }
    }
    if(block == 0 && neededBlock ==0){
        return 0;
    }
    if(neededBlock> (B+block)) // 블록이 부족한 경우
        return INF;

    return block *2 + neededBlock;
}