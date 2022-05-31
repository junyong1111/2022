#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N = 0; 
    int target_M = 0;
    cin >> N >> target_M;
    int min_coins = 0;
    vector<int>coins(N,0);
    for(int i=0; i<N; i++)  
        cin >> coins[i];
    for(int i=N-1; i>=0; i--){
       if(target_M>=coins[i]){
           min_coins += target_M/coins[i];
           target_M = target_M %coins[i];
       }
    }
    cout << min_coins << "\n";
    return 0;
}