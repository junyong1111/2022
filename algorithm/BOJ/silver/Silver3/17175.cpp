#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[51];

int fibonacci(int n);

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int n = 0;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    
    int fibo = fibonacci(n);
    cout << fibo << "\n";

    return 0;
}

int fibonacci(int n) { // 호출
    if(dp[n]!=0){
        return dp[n];
    }
    else{
        dp[n] = (fibonacci(n-2) + fibonacci(n-1) +1) % 1000000007;
        return dp[n];
    }

}