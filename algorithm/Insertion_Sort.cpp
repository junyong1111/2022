#include <iostream>
#define N 5
using namespace std;

int main(){


int idx=0;
int cnt = 0;
int arr[N] = {29,13,14,37,10};
int temp = 0;

// 13 14 29 37 10
for(int i=1; i<N; i++){
    if(i==3)break;
    if(arr[i-1] >= arr[i]){
        temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
        idx--;
    }
    temp = arr[i+1]; // //i :1
    cout << "current I is " << i << endl;
    cout << "temp is " << temp << endl;
    idx =i; // 3 ->29
    while(temp<=arr[idx])
    {
            arr[idx+1] = arr[idx];
            arr[idx] = temp;
            idx--;
            cout << "현재값은 " << arr[idx+1]<<endl;
            cout << "이전값은 " << arr[idx]<<endl;
    } //while
    
}

for(int i=0; i<N; i++)
    cout << arr[i] << " " ;
return 0;

}