#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
// 벌집 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 1;
    int Pow = 2;
    
    // 중앙1에서부터 
    // 3 * 2*i
    int Num = 0;
    cin >> Num;
    Num = Num-1;
    while(Num>0)
    {
        Num = Num - 3*Pow; 
        Pow  += 2;
        cnt ++;
    }
    cout << cnt ;
    return 0;
}