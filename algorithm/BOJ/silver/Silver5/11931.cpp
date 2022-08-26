#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r",stdin);

    int num = 0;
    cin >> num;

    vector<int>V(num,0);

    for(int i=0; i<num; i++){
        cin >> V[i];
    }

    sort(V.rbegin(), V.rend());

    for(int i=0; i<num; i++){
        cout << V[i] <<"\n";
    }


    return 0;
}