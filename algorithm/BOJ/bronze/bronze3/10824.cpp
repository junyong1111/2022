#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    string A,B,C,D;
    cin >> A>> B >> C>> D;

    A = A + B;
    C = C + D;
    
    long long sum = stoll(A) + stoll(C);

    cout << sum << "\n";

    return 0;
}