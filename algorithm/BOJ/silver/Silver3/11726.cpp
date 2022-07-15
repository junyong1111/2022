#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>DP(1001, 0);

int Tileing(int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    int N = 0;
    cin >> N;
    DP[1] = 1%10007;
    DP[2] = 2%10007;
    int answer = Tileing(N);

    cout << answer << "\n";
    return 0;
}

int Tileing(int N){
    if(DP[N]!=0)
        return DP[N]%10007;
    else{
        DP[N] = (Tileing(N-1)) + (Tileing(N-2));
        return DP[N]%10007;
    }
}