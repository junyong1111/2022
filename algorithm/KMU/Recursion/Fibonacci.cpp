#include <iostream>

using namespace std;

int fibo(int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int tsetCase = 0;
    cin >> tsetCase;

    while(tsetCase--){
        int number = 0;
        cin >> number ;
        cout << fibo(number) <<"\n";
    }
    return 0;
}

int fibo(int N){
    if(N<=1){
        return N;
    }
    else{
        return fibo(N-1) + fibo(N-2);
    }
}