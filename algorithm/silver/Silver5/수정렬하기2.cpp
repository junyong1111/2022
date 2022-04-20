#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N =0;
    cin >> N;
    vector<int>ans;
    for(int i=0; i<N; i++){
        int temp = 0;
        cin >> temp;
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());
    for(int i=0; i<N; i++)
        cout << ans[i] << "\n";
    return 0;
}
