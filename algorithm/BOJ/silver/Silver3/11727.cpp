#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>DP(1001,0);

int Tileing(int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int N = 0;
    cin >> N;

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 3;
    DP[3] = 5;
    int answer = Tileing(N);
    cout << answer << "\n";
    
    return 0;
}

int Tileing(int N){
    if(DP[N]!=0){
        return DP[N];
    }
    else{
        DP[N] =  ( (Tileing(N-1) + Tileing(N-2)*2 )) % 10007;
        return DP[N];
    }
}