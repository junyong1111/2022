#include <iostream>
#include <vector>

using namespace std;

string White[8] ={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
}; //흰색 체크보드
string Black[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
}; //검은색 체크보드

int checkBoard(vector<vector<char> > chess, int i, int j){
    int result_W = 0; // 흰 체크보드 결과
    int result_B = 0; // 검은 체크보드 결과
    
    for(int y=0; y<8; y++){ // 체스판을 전체를 돌아다님
        string ans_w = White[y]; // 화이트보드 y번째 줄
        string ans_b = Black[y]; // 블랙보드 y번째 줄
        for(int x=0; x<8; x++){
            if(ans_w[x]!=chess[y+i][x+j]) // 이동해야하므로 인덱스 + 매개변수 값
            result_W++; // 화이트보드 필요한 수정개수 
            else if(ans_b[x]!=chess[y+i][x+j])  // 이동해야하므로 인덱스 + 매개변수 값
            result_B++;// 블랙보드 필요한 수정개수
        }
    }
    int min  = result_W<=result_B?result_W:result_B; // 두 개의 보드의 최솟값 return
    return min;
}//check fun
    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N,M;
    cin >> N >> M;
    
    vector<vector<char> >chess(N, vector<char>(M));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> chess[i][j] ;

    int result  = 10000000;
    
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            result = result<checkBoard(chess,i,j)?result:checkBoard(chess,i,j);
        }
    }
    cout << result << "\n";
    return 0;
}