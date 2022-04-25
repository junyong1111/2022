#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >>N;
    
    vector<int>A(N,0);
    vector<int>B(N,0);
    int sum =0;

    for(int i=0; i<N; i++){
        int temp = 0;
        cin >> temp;
        A[i] = temp;
    }
    for(int i=0; i<N; i++){
        int temp = 0;
        cin >> temp;
        B[i] = temp;
    }
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
   
    for(int i=0; i<N; i++){
        sum += A[i] * B[i];
    }
    cout << sum <<"\n";
    

    return 0;
}