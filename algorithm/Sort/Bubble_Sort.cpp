#include <iostream>
#define N 5
using namespace std;

int main(){

int arr[N] = {10,29,14,37,13};
int len = N-1; 
int max = 0;
for(int i=0; i<N-1; i++){    
    for(int j=0; j<=len-1; j++){
        max = arr[j]; // 앞 Index값 삽입
        if(max>arr[j+1]){ // 앞 Index값이 더 크면 Swap
            int temp = arr[j]; //Swap
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    len --; // 맨 마지막 정렬은 완료되었으니 1개 축소
}
for(int i=0; i<N; i++)
    cout << arr[i] << " " ;
return 0;
}
