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


<details>
<summary> 1. Selection Sort(선택 정렬) </summary>
<div markdown="1">   

### 선택정렬의 아이디어는 다음과 같다 
1. 배열 중 가장 큰 값을 찾는다  
2. 가장 큰 값과 마지막 Index와 Swap  
3. 반복이 한 번 끝날때마다 맨 마지막은 Index은 정렬이 완료 따라서 체크 할 필요가 없다.

위 과정을 반복  

**O(n^2)** 알고리즘이며 항상 모든 값을 확인해야 하므로 시간복잡도는 항상 같다.

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

### 의사코드
![Selection_Sort](https://user-images.githubusercontent.com/79856225/163812353-6c9021bf-4aa3-4a35-afd9-2c636434e0ef.jpeg)


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
</div>
</details>


<details>
<summary> 2. Bubble Sort(버블 정렬) </summary>
<div markdown="1">   

### Selection Sort와 아이디어는 비슷하며 물고기를 몰아서 그물로 잡는거와 비슷하다. (큰 물고기는 그물을 빠져나갈 수 없음)
1. 배열의 현재값과 그 다음 값을 비교하여 더 큰 값을 찾는다.
2. 큰 값을 더 뒤 Index로  Swap
3. 한 사이클 반복이 끝날때마다 맨 마지막 Index는 정렬이 완료

위 과정 반복

**O(n^2)** 알고리즘이며 항상 모든 값을 확인해야 하므로 시간복잡도는 항상 같다.

ex)
```c++
[29, 10, 14, 37, 13]
```
1. arr[0] 과 arr[1] 중 Max값 비교 Max = 29
2. 더 큰 값의 Index를 더 뒤로 Swap

```c++
[10,29,14,37,13]
```
1. arr[1] 과 arr[2] 중 Max값 비교 Max = 29
2. 더 큰 값의 Index를 더 뒤로 Swap

```c++
[10,14,29,37,13]
```
위 과정 반복...


### Bubble Sort 구현

```c++
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

```
</div>
</details>


<details>
<summary> 3. Insertion Sort(삽입 정렬) </summary>
<div markdown="1">   


뒤에서부터는 체크해야함 그 이유는 어차피 앞에서부터 확인 해서 들어갈 자리를 확인하더라도 뒤에서 부터 한 자리씩 Shift하는 과정이 필요함

#### Insert하기 전 Index까지는 이미 정렬이 되었다고 가정

1. Insert하고 싶은 값을 미리 temp변수에 저장
2. Insert값 이전 Index부터 값을 확인 후 temp보다 더 크 한 칸씩 Shift
3. temp 보다 더 작은 값을 만나거나 첫 Index라면 그 자리에 temp 값을 Insert

위 과정을 반복

최악의 경우 O(n^2)의 수행시간  
최선의 경우 O(n-1)의 수행시간  
최악의 경우를 제외하고 Selection Sort나 Bubble Sort 보다 수행시간이 짧다.



ex)
```c++
[29, 10, 14, 37, 13]
```
####  #N 1일 때는 이미 정렬 되었다고 가정 1번Index(10)부터 시작
1. 임시 변수temp에 10의 값을 저장 
2. arr[0] (현재29) 이 temp(insert)값보다 더 크다면 한 칸 Shift
3. temp 보다 더 작은 값을 만나거나 첫 Index라면 그 자리에 temp 값을 Insert

```c++
[10,29,14,37,13]
```

1. 임시 변수 temp에 14의 값을 저장
2. arr[1] (현재29)이 temp(insert)값보다 더 크다면 한 칸 Shift
3. temp 보다 더 작은 값을 만나거나 첫 Index라면 그 자리에 temp 값을 Insert

```c++
[10,14,29,37,13]
```
위 과정을 반복

### Insertion Sort 구현

```c++
#include <iostream>
#define N 5
using namespace std;

int main(){

int idx=0;
int arr[N] = {29, 10, 14, 37, 13};
int temp = 0;

for(int i=1; i<N; i++){
    temp = arr[i]; 
    idx = i; //현재 i의 값을 저장
    while(arr[idx] <= arr[idx-1]){ 
        // 제일 처음은 정렬이 되었다고 생각하고 그 다음부터 작은값이 나올때까지 한자리씩 Swap
        arr[idx] = arr[idx-1];
        arr[idx-1] = temp;
        idx --;
    }
}
for(int i=0; i<N; i++)
    cout << arr[i] << " " ;
return 0;
}
```


</div>
</details>
