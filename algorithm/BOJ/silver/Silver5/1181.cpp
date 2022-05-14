#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string const &a, string const &b){
    if(a.length()<b.length()){
        return true;
    }
    else if(a.length() == b.length()){
        return a<b;
    }
    else 
        return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Len; 
    cin >> Len;

    vector<string>ans(Len);

    for(int i=0 ;i<Len; i++){
        string str;
        cin >> str;
        ans.push_back(str);
    }
    
    stable_sort(ans.begin(), ans.end(), compare);
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    
    for(vector<string>::iterator it = ans.begin()+1; it!=ans.end(); it++)
        cout << *it << "\n";
    
    return 0;
}