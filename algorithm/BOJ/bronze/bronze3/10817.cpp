#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    vector<int>ans;
    vector<int>::iterator it = ans.begin();
    for(int i=0; i<3; i++){
        int num = 0;
        cin >> num;
        ans.push_back(num);
    }

    sort(ans.rbegin(), ans.rend());
    cout << ans[1];
    
    return 0;
}
// 벡터를 이용하여 내림차순 정렬 이후 가운데 원소를 프린트하여 간단하게 해결가능