#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K ;
    int idx = K-1;
    vector<int> ans;
    for(int i=0; i<N; i++)
        ans.push_back(i+1);

    cout << "<";
    for(int i=0; i<N-1; i++){
        cout << ans[idx] << ", ";
        ans.erase(ans.begin() +idx);
        idx =  (idx+ K-1)% ans.size() ;   
    }
    cout << ans.back();
    cout << ">\n";
    
    return 0;
}
