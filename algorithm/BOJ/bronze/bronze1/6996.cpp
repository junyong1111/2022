#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        string a,b;
        string tempA, tempB;
        cin >> a >> b;
        tempA = a;
        tempB = b;

        sort(tempA.begin(), tempA.end());
        sort(tempB.begin(), tempB.end());


        if(tempA == tempB){
            cout << a << " & " << b << " are anagrams.\n";
        }
        else{
            cout << a << " & " << b << " are NOT anagrams.\n";
        }
 
    }

    return 0;
}