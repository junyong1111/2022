#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int len = 0;
    cin >> len;
    string str;
    cin >> str;
    int sum = 0;

    for(int i=0; i<len; i++){
        sum+= str[i] - 64;
    }
    cout << sum ;
    return 0;

}