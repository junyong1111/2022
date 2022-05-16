// 오셀로 게임

#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 8

using namespace std;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1}; 
// 좌,우,상,하,오른위,오른아래,왼위,왼아래
bool flag = false; // balck is false

typedef struct Point{
    int x;
    int y;
}P;

void init(vector<vector<char> >&GRID){
    GRID[3][3] = 'O';
    GRID[4][4] = 'O';
    GRID[3][4] = 'X';
    GRID[4][3] = 'X';
    flag = false;
}

char Color(){
    return flag==false?'X':'O';
}

bool Flag(){
    return flag==false?true:false;
}

void insert(vector<vector<char> >&GRID, P pos){
    pos.x --;
    pos.y --;
    char color = Color();
    GRID[pos.y][pos.x] = color;

    for(int i=0; i<SIZE; i++){
        int check_X = pos.x+dx[i];
        int check_Y = pos.y+dy[i];
         int cnt = 0;

        if((check_X<SIZE && check_X>=0) && (check_Y<SIZE && check_Y>=0))
        {   
            bool find = true;
            while(GRID[check_Y][check_X] != color ){
                if(GRID[check_Y][check_X] == '+'){
                    find = false;
                    break;
                } // 같은돌을 만나기전에 종료                   
                check_X += dx[i];
                check_Y += dy[i];
                cnt ++;
                find = true;
            if((check_X>=SIZE || check_X<0) || (check_Y>=SIZE || check_Y<0)){
                    find = false;
                    break;
                } // 증가하다가 범위 밖을 만나버림
            }//while //같은돌 만나면 끝!
            
            if(find == true)
            {
                int temp_y = pos.y+ dy[i];
                int temp_x = pos.x+ dx[i];
                while(cnt>0){
                    GRID[temp_y][temp_x] =  color;
                    temp_y += dy[i];
                    temp_x += dx[i];
                    cnt--;
                }
            }   
        }//범위에존재 
    }//사각 체크
    flag = Flag(); // 돌 바꾸기
}

void BW(vector<vector<char> > &Grid){
    int B = 0;
    int W = 0;
    for(int i=0 ;i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(Grid[i][j] == 'X')
                B++;
            else if(Grid[i][j] == 'O')
                W++;
            else
                continue;
        }    
    }  // 돌의 갯수 출력
    cout << B << " " << W << "\n";
}
void print(vector<vector<char> >&GRID){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << GRID[i][j];
        }
        cout << "\n";
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // freopen("input.txt", "r", stdin);
    int testCase = 0;
    cin >> testCase;
    while(testCase--){
        vector<vector<char> >GRID(SIZE, vector<char>(SIZE, '+'));
        init(GRID);
        P pos;
        int Num = 0 ;
        cin >> Num;
        while(Num--){
            cin >> pos.y >> pos.x;
            insert(GRID, pos);
        } // Game Number
        BW(GRID);
        print(GRID);
    } //testCase
    return 0;
}