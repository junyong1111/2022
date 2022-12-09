#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int number = 0;
    cin >> number;

    vector<int>lope(number, 0);

    for(int i=0; i<number; i++)
        cin >> lope[i];
    //
    sort(lope.rbegin(), lope.rend());
    
    int k = 0;
    int weightMax = 0;
    int value = 0;
    for(int i=1; i<= number; i++){
        value  = lope[i-1] * i;

        if(weightMax<value){
            weightMax = value;
            k = i;
        }
    }
    cout << weightMax << "\n";

    return 0;
}