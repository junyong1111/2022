#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str ;
    cin >> str;
    vector<int>alpha(26,0);
    int len = str.length();
    for(int i=0; i<len; i++){
        alpha[str[i]-97] ++;
    }
    for(vector<int>::iterator it = alpha.begin(); it!=alpha.end();it++){
        cout << *it << " " ;
    }
    cout << "\n";

    return 0;
}