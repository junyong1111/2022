#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int testCase = 0;
    cin >> testCase;
    int Sum =0;
    string str;

    while(testCase--){
        cin >> str;
        Sum = 0;
        for(int i=0; i<3; i++){
            if(str[i] == ','){
                continue;
            }
            else{
                Sum = Sum + str[i] - '0';
            }
        }
        cout << Sum << "\n";
    }

    return 0;
}