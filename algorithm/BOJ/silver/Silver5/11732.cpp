#include <iostream>
#include <string>

using namespace std;

int S[20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt" ,"r" ,stdin);

    int numOfoperator = 0;
    cin >> numOfoperator;
    
    int value = 0;

    while(numOfoperator--){
        string str;
        cin >> str;

        if(str == "add"){
            cin >> value;
            if(S[value-1]==0){S[value-1] = 1;}
        }

        else if(str == "remove"){
            cin >> value;
            if(S[value-1] == 1){S[value-1] =0;}
        }

        else if(str == "check"){
            cin >> value;
            cout << (S[value-1]==1) <<"\n";
        }

        else if(str == "toggle"){
            cin >> value;
            if(S[value-1] == 1){S[value-1] = 0;}
            else {S[value-1] = 1;}
        }

        else if(str == "all"){
            for(int i=1; i<21; i++)
                S[i-1] = 1;
        }
        else{
            for(int i=1; i<21; i++)
                S[i-1] = 0;
        }
    }
    return 0;
}