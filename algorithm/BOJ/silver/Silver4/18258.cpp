#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    queue<int>Q;
    int testCase = 0;
    cin >> testCase;
    string str;

    while(testCase--){
        cin >> str;
        if(str=="push"){
            int temp = 0;
            cin >> temp;
            Q.push(temp);
        }
        else if(str=="pop"){
            if(!Q.empty()){
            int temp = Q.front();
            Q.pop();
            cout << temp << "\n";
            }
            else{
                cout << -1 <<"\n";
            }
        }
        else if(str=="size"){
            cout << Q.size() <<"\n";
        }
        else if(str=="empty"){
            cout << Q.empty() <<  "\n";
        }
        else if(str=="front"){
            if(!Q.empty()){
                int temp = Q.front();
                cout << temp << "\n";
            }
            else{
                cout << -1  <<"\n";
            }
        }

        else if(str=="back"){
            if(!Q.empty()){
                int temp = Q.back();
                cout << temp << "\n";
            }
            else{
                cout << -1  <<"\n";
            }
            
        }
    }

    return 0;
}