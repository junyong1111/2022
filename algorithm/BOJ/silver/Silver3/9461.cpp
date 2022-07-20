#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll  DP[101]; 
// 오버플로우 방지

ll P(int N);
// 오버플로우 방지

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;

    // 5번까지 미리 삽입
 
    int testCase = 0;
    cin >> testCase ;

    while(testCase--){
        int N = 0;
        cin >> N;
        cout << P(N) <<"\n";
    }// while


    return 0;
}

ll P(int N){
    if(DP[N]!=0){
        return DP[N];
    }
    else{
        DP[N] = P(N-1) + P(N-5);
        // DP[N] = DP[N-1] + DP[N-5]의 패턴
        return DP[N];
    }
}