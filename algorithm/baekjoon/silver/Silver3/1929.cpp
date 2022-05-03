#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrimeNum(int M, int N)
{
    vector<int>Prime(1000001, 0);
    Prime[0] = 1;
    Prime[1] = 1;
    for(int i=2; i*i<1000001; i++)
        for(int j=2*i; j<1000001; j=j+i)   
            if(Prime[i] == 0)
                Prime[j] =1;        
   
    for(int i=M; i<=N; i++)    
        if(Prime[i]==0)
            cout << i << "\n";         
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    PrimeNum(M,N);
    return 0;
}