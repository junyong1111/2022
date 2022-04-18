#include <iostream>
#define N 5
using namespace std;

int main(){

int arr[N] = {24, 120, 64, 37, 13};
int max = 0;
int Last = N-1;
int k = 0;
int cnt = 0;

for(int i=0; i<N-1; i++){
    max = arr[0];
    k=i;
    for(int j=0; j<=Last; j++){
        if(max <= arr[j]){
            max = arr[j];
            k = j;
        }
    }
    int temp = arr[Last];
    arr[Last] = arr[k];
    arr[k] = temp;
    Last --;
}

for(int i=0; i<N; i++)
    cout << arr[i] << " " ;
return 0;
}
