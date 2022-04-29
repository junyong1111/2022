#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long>ans(100,0);


long long fib(int N){
    if(N<=1)
        return N;
    else{
        long long idx = N-2;
        if(ans[idx]==0){
            ans[idx] = fib(N-2) +fib(N-1);
            return ans[idx];
        }
        else{
            return ans[idx];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    cout << fib(N);
    return 0;
}