#include <iostream>
#define N 5
using namespace std;

int main(){

int idx=0;
int arr[N] = {29, 10, 14, 37, 13};
int temp = 0;

for(int i=1; i<N; i++){
    temp = arr[i]; 
    idx = i;
    while(arr[idx] <= arr[idx-1]){
        arr[idx] = arr[idx-1];
        arr[idx-1] = temp;
        idx --;
    }
}
for(int i=0; i<N; i++)
    cout << arr[i] << " " ;
return 0;
}