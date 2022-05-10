#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int phone(char str){
    switch(str){
        case 'A' : case 'B' : case 'C':
        return 2;
        case 'D' : case 'E' : case 'F':
        return 3;
        case 'G' : case 'H' : case 'I':
        return 4;
        case 'J' : case 'K' : case 'L':
        return 5;
        case 'M' : case 'N' : case 'O':
        return 6;
        case 'P' : case 'Q' : case 'R': case 'S':
        return 7;
        case 'T' : case 'U' : case 'V':
        return 8;
        case 'W' : case 'X' : case 'Y': case 'Z':
        return 9;

    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    int ans = 0;
    cin >> str;
    int len = str.length();
    vector<int>v (len, 0);

    for(int i=0; i<len; i++){
        v[i] = phone(str[i]);
        ans = ans+v[i]+1;
    }
    cout << ans << "\n";
    return 0;
}