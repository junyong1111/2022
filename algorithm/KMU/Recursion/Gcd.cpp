#include <iostream>

using namespace std;

int gcd(int a, int b); 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int a = 0;
        int b = 0;
        cin >> a >> b;
        cout << gcd(a,b) << "\n";
    }

    return 0;
}

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}