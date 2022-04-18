# 정렬(Sort)
### 정렬 알고리즘
정렬 알고리즘은 크게 2가지로 나뉠 수 있다.  
간단하지만 느린 알고리즘 , 조금 더 복잡하지만 빠른 알고리즘 
- Simple , Slow(간단하지만 느림)
    - Selection Sort(선택 정렬)   
    - Bubble Sort(버블 정렬)
    - Insertion Sort(삽입 정렬)
     

- Fast(위 알고리즘보다 복잡하지만 빠름)
    - Merge Sort(병합 정렬)
    - Quick Sokt(빠른 정렬)
    - Heap Sort(힙 정렬)

## Simple , Slow

### 1. Selection Sort(선택 정렬) 
선택정렬의 아이디어는 다음과 같다 
1. 배열 중 가장 큰 값을 찾는다  
2. 가장 큰 값과 마지막 Index와 Swap  

위 과정을 반복  
ex)
```c++
 [29, 10, 14, 37, 13]
 ```
 1. 배열 중 가장 큰 값을 찾는다. 
 Max = 37
 2. 가장 큰 값과 마지막 Index를 Swap
 Max = 37 , Index = 13 
 -> Swap 
```c++
[29, 19, 14, 13, 37]
```
위 과정 반복

### Selection Sort 구현

```c++

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



```
