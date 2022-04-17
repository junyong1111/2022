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

    sort(ans.begin(), ans.end());
    for(it = ans.begin(); it!=ans.end(); it++){
        cout <<*it << " ";    }
    
    return 0;
}