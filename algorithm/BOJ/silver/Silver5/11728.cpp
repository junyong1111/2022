#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" ,"r", stdin);

    int sizeA = 0;
    int sizeB = 0;
    cin >> sizeA >> sizeB;
    vector<int>C(sizeA+sizeB, 0);

    for(int i=0; i<sizeA+sizeB; i++)
        cin >> C[i];
        
    sort(C.begin(), C.end());

    for(auto c : C)
        cout << c << " ";
    cout << "\n";
    
    return 0;
}