#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2100000000

using namespace std;

vector<int>DP(100000,0);
vector<int>coins(2,0);

int Coins(int change);
int change;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    coins[0] = 5;
    coins[1] = 2;
    
    cin >> change;
    
    int answer = Coins(change);
    if(answer>=INF){
        cout << -1 << "\n";
        return 0;
    }
    cout << answer << "\n";

    return 0;
}

int Coins(int change){
    if(change<0)
        return INF;
    
    if(change ==0)
        return 0;

    if(DP[change]!=0)
        return DP[change];

    int min = INF;
    for(int i=0;i<2; i++){
        int temp = Coins(change-coins[i]);
        if(temp<min){
            min = temp;
        }
    }

    DP[change] = min+1;

    return DP[change];
}