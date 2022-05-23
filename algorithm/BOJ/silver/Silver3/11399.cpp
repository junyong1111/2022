#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int N = 0;
    cin >> N;

    vector<int>ans(N,0);
    for(int i=0 ;i<N; i++)
        cin >> ans[i];
    stable_sort(ans.begin(), ans.end());
    int answer = 0;
    for(int i=1; i<N; i++)
        ans[i] = ans[i] + ans[i-1];
    for(int i=0; i<N; i++)
        answer += ans[i];
    cout << answer << "\n";
    return 0;
}