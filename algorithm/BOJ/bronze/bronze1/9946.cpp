#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    string a;
    string b;
    
    cin >> a >> b;
    int idx = 1;
    while(a!="END" && b!="END"){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a==b){
            cout << "Case " << idx << ": " <<  "same\n";
        }
        else{
            cout << "Case " << idx << ": " <<  "different\n";
        }
        idx++;
        cin >> a >> b;
    }

    return 0;
}