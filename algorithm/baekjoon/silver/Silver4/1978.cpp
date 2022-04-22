#include <iostream>
#include <vector>

#define N 1000000
using namespace std;

int main(){
    int cnt = 0;
    int Num;
    cin >> Num;
    vector<int>ans(N+1,0);
    ans[0]=1;
    ans[1]=1;
    for(int i=2; i*i<=N; i++){
        if(ans[i]==1)
            continue;
        else{
            for(int j=2*i; j<=N; j=j+i)
                ans[j] = 1;
        }
    }
    while(Num--)
    {   
        int prime=0;
        cin >> prime;
        if(ans[prime] == 0){cnt++;}
    }
    cout << cnt;
    return 0;
}