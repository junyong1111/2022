#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int>temp(4,0);
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    int ans = 0;

    temp[0] = w - x;
    temp[1] = h - y;
    temp[2] = x ;
    temp[3] = y;
    sort(temp.begin(), temp.end());
    ans = temp[0];    
    cout << ans <<"\n";

    return 0;
}