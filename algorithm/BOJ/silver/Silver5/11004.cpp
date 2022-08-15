#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int size = 0;
    int target =0 ;
    cin >> size >> target;

    vector<int>V(size, 0);
    for(int i=0; i<size; i++)
        cin >> V[i];
    
    sort(V.begin(), V.end());

    cout << V[target-1] << "\n";



    return 0;
}