#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt" , "r", stdin);

    int Num , Target;
    cin >> Num >> Target;

    map<string, int>DOGAM;
    vector<string>DOGAM2;

    for(int i=1; i<=Num; i++){
        string name;
        cin >> name;
        DOGAM.insert(make_pair(name,i));
        DOGAM2.push_back(name);
    }
    
    while(Target--){
        char str[100];
        cin >> str;
        // cout << atoi(str) << "\n"
        // 정수를 입력받으면 그대로 나오고 문자열을 입력받으면 0이 나오넹
        if(atoi(str))
            cout << DOGAM2[atoi(str)-1] << "\n";
        else
            cout << DOGAM[string(str)] << "\n";
    }
    return 0;
}

