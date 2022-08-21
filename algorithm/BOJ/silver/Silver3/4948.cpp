#include <iostream>
#include <vector>
#include <cmath>
#define SIZE (123456*2) +1

using namespace std;

vector<int>PrimeNumber(SIZE, 0);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    PrimeNumber[0] = 1;
    PrimeNumber[1] = 1;

    int size = sqrt(SIZE); // 주어진 사이즈의 루트만큼만 반복문을 돌아도 충분하다.
    for(int i=2; i<=size; i++){ 
        if(PrimeNumber[i] ==0){
            for(int j=i*2; j<=SIZE; j =j+i){
                PrimeNumber[j] = 1;
            }
        }
    }
    
    int N=0;
    cin >> N;
    while(N!=0){
        int cnt = 0;
        for(int i=N+1; i<=2*N; i++){
            if(PrimeNumber[i]==0)
                cnt++;
        }
        cout << cnt << "\n";
        cin >> N;
    }
    
    return 0;
}