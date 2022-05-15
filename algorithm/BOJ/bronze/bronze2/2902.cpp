#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    int len = str.length();
    for(int i=0; i<len; i++){
        if(str[i] >='A' && str[i] <='Z')
        {cout << str[i];}
    }
    cout << "\n";
    return 0;
}