#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n){
    if(n<=1){
        return 1;
    }
    else{
        return factorial(n-1)*n;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , k;
    cin >> n >> k;
    if(k==0){cout << 1 <<"\n"; return 0;}
    if(k>n){return 0;}
    cout << factorial(n) / (factorial(k) * factorial(n-k))  << "\n";

    return 0;
}