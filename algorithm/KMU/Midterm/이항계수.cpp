#include <iostream>
#define MAX_SIZE 101
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

long long binary(int n, int k);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase =0;
    cin >> testCase;

    while(testCase--){
        int n = 0;
        int k = 0;
        cin >> n >> k;
    
        cout << binary(n,k)%1000 << "\n";
    }


    return 0;

}


long long binary(int n, int k){
    int i,j;
    int V[MAX_SIZE][MAX_SIZE];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=MIN(i,k); j++){
            if(j==0 || j==i)
                V[i][j] = 1;
            else
                V[i][j] = V[i-1][j-1]%10000 + V[i-1][j]%10000;
        }
    }
    return V[n][k];
}