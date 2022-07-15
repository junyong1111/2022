#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int>DP(301,0);

int Climbing_Stairs(vector<int> &Score, int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r" , stdin);

    int N = 0;
    cin >> N;
    vector<int>Score(N+1,0);
    for(int i=1; i<=N; i++)
        cin >> Score[i];

    DP[1] = Score[1]; 
    DP[2] = DP[1]+Score[2]; 
    DP[3] = max(Score[1], Score[2]) + Score[3];
    // 최초 3개의 DP테이블 셋팅

    int answer = Climbing_Stairs(Score, N);
    cout << answer << "\n";
    return 0;
}

int Climbing_Stairs(vector<int> &Score, int N){
    if(DP[N] !=0 ){
        return DP[N];
    }// 이미 값이 있다면 값을 리턴
    else{
        int MAX = Climbing_Stairs(Score, N-2)+Score[N]; // 최초 값을 저장
        for(int i =N-3; i>0; i--){
            int t_m = Climbing_Stairs(Score, i) + Score[N]; // 자신 + DP[N-3]의 값을 저장
            int temp = i+2; // 2칸씩 증가함
            while(temp<N){
                t_m = t_m+ Score[temp]; // 2칸 전 값을 저장
                temp = temp +2;
            }
            MAX = max(MAX, t_m);    //최대값 갱신
        }  
        DP[N] = MAX; //최대값 테이블에 저장
        return DP[N];
    }
}