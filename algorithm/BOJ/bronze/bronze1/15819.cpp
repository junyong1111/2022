#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int VectorSize = 0;
    int TargetNumber = 0;
    cin >> VectorSize >> TargetNumber;

    vector<string>V(VectorSize);
    for(int i=0; i<VectorSize; i++)
        cin >> V[i];
    sort(V.begin(), V.end());

    cout << V[TargetNumber-1] <<"\n";


    



    return 0;
}