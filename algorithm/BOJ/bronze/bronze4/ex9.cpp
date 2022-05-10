#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H ,M ,T;
    cin >> H >> M >> T;
    M += T;
    while(M>=60){
        H = H + M/60;
        M = M%60;
    }
    while(H>=24){
        H= H - 24;
    }
    cout << H << " " << M;
    return 0;
}

