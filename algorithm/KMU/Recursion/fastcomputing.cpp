#include <iostream>

using namespace std;

typedef long long ll;

ll fastcomputing(ll x, ll n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int x = 0;
        int n = 0;
        cin >> x >> n;
        cout << fastcomputing(x,n)%1000 <<"\n";
    }

    return 0;
}


ll fastcomputing(ll x, ll n){
    ll temp = 1;
    while(n){
        if(n&1)
            temp = temp*x%10000;
        n = n/2;
        x = x*x%10000;
    }
    return temp;
}