#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int>ans;
    vector<int>::iterator it = ans.begin();

    int A,B,C;
    int sum = 0;
    cin >> A >> B >> C;
    ans.push_back(A);
    ans.push_back(B);
    ans.push_back(C);
    sort(ans.begin(), ans.end());
    if (A == B  && A== C){
        sum = 10000 + (A*1000);
        cout << sum;
        return 0;
    }
    else if(A==B || A==C){
        sum = 1000+(A*100);
        cout << sum;
        return 0;
    }
    else if(C==B){
        sum = 1000+(C*100);
        cout <<sum;
        return 0;
    }
    else{
        cout <<ans[2]*100;
    }
    return 0;
}