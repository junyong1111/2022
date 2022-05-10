#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int testCase = 100;
    while(testCase--)
    {
        getline(cin, str);
        cout << str << "\n";
    }
    return 0;
}
