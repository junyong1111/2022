#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    long long r = 1;
    long long Mod = 1234567891;

    int len = 0;
    cin >> len;
    string str ;
    cin >> str;
    long long answer = 0;
    for(int i=0; i<len; i++){
        long long temp = str[i]-96;
        temp = temp * r;
        answer += temp;
        r *=31;
        r = r % Mod;
    }
    answer = answer % Mod;
    cout << answer <<"\n";
    return 0;
}