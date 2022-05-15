#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    vector<int>Prime(10000,0);
    Prime[0] = 1;
    Prime[1] = 1;
    int M,N;
    cin >>  M >> N;
    vector<int>ans;
    int sum = 0;

    for(int i=2; i*i<=N; i++){
        for(int j=2*i; j<=N; j=j+i){
            if(Prime[i]==0){
                Prime[j] =1;
            }
        }
    }
    for(int i=M; i<=N; i++){
        if(Prime[i] == 0){
            sum += i;
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size()==0){
        cout << "-1\n";
    }
    else{
    cout << sum <<"\n";
    cout << ans[0] ;
    }
    
    return 0;   
}