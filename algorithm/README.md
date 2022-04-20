
# 정렬(Sort)
<details>
<summary> 정렬 알고리즘 </summary>
<div markdown="1">  


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

</div>
</details>


### **Simple , Slow**



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
  

### **Fast (분할정복법)**



<details>
<summary> 1. Merge Sort(합병 정렬) </summary>
<div markdown="1">   

- 분할 : 해결하고자 하는 문제를 작은 크기의 **동일한** 문제들로 분할
- 정복 : 각각의 작은 문제를 순환적으로 해결
- 합병 : 작은 문제의 해를 합하여(Merge) 원래 문제에 해를 구함

1. 데이터가 저장된 배열을 절반으로 나눔
2. 각각을 순환 정렬
3. 정렬된 두 개의 배열을 합쳐 전체를 정렬!

ex)
```c++
[12,24,63,12,51,2,125,32]
```
1. 데이터를 절반으로 나누고 순환하여 정렬
```c++
[12,12,24,63] , [2,32,51,125]
      ↓               ↓
[12,24], [12,63] , [2,51] , [32,125]
   ↓        ↓         ↓         ↓
[12],[24],[63],[12] ,[51],[2],[125],[32] 
```
2.  합병 후 정렬
```c++
[2,12,12,24,32,51,63,125]
```


## 정렬된 두 배열을 합쳐야 하므로 추가적인 배열을 이용하여 합병해야 한다 
- 1번 배열은 i idx 
- 2번 배열은 j idx 
- 둘 중 더작은값을 새로운 배열의 맨 처음에 삽입
- 한 쪽 배열의 index가 끝나면 나머지 배열의 값을 전부 추가 배열의 삽입


Mergesort(int Arr[], int left ,int right , int new)
1. left,right 의 중간 지점 계산
2. left정렬
3. right정렬
4. left , right합병

O(nlogn)의 수행시간 

### Merge Sort 구현

```c++
#include <iostream>
#include <algorithm>
#define SIZE 8
using namespace std;

void Merge(int arr[], int start, int mid, int end){
	int i = start;
	int j = mid+1;
	int idx = start;
	int len = SIZE;
	int *temp = new int[len];

	while(i<=mid && j<=end){ // 둘 중 하나라도 끝날때까지
		if(arr[i] <= arr[j])
			temp[idx++] = arr[i++];
		else
			temp[idx++] = arr[j++];
		 
	}	//while	
	while(i<=mid)
		temp[idx++] = arr[i++]; // 앞쪽 데이터가 남아있다면
	while(j<=end)
		temp[idx++] = arr[j++]; // 뒤쪽 데이터가 남아있다면 

	for(int k=start; k<=end; k++)
		arr[k] = temp[k];
	delete[] temp;
}
void Merge_Sort(int arr[], int start,int end){
	if(start < end){ //시작보다 끝이 더 길어야 함 그게 아니라면 길이가 1개
		int mid = (start+end)/2; //시작과 끝의 중간지점
		Merge_Sort(arr, start, mid); //시작과 중간을 정렬
		Merge_Sort(arr, mid+1, end); // 중간과 끝을 정렬
		Merge(arr,start ,mid , end); // 합병 정렬
	}
}

int main(){
	int arr[] = {12,24,63,12,51,2,125,32};
	int start = 0;
	int end = SIZE-1;

	Merge_Sort(arr,start,end);
	for(int i=0; i<=end; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;

}


```
마지막 Merge하는 부분이 ..상당히 어려웠다.

</div>
</details>



<details>
<summary> 2.Quick Sort(빠른정렬)</summary>
<div markdown="1">  
  
- 분할 : 조건을 이용하여 두 부분으로 분할
- 정복 : 각각의 문제를 순환적으로 해결
- 합병 : 합병과정은 없음

Pivot(기준)을 이용하여   
Pivot보다 작은 수<- Pivot -> Pivot보다 큰 수  
두 부분으로 분할 후 정렬  
Merge Sort와는 다르게 합병하는 과정이 없다.

ex)

```c++
[12,24,63,12,51,2,125,32]
```
맨 마지막 값을 기준으로 정렬

```c++
[12,24,12,2] <- [32] -> [63,51,125] 
```
왼쪽데이터와 오른쪽데이터 정렬

```c++
[2,12,12,24,32,51,63,125]

```


최악의 경우를 제외하고는 **O(nlogn)**의 수행속도  
최악의 경우는 이미 배열이 정렬된 경우이고 O(n^2)의 수행속도     
### 최악을 제외하고 이름처럼 가장 빠른 정렬 알고리즘이며 \<algorithm>의 sort()함수가 QuickSort이다.

### 의사코드
![IMG_0416](https://user-images.githubusercontent.com/79856225/164193808-16f69515-bf22-4113-a38a-1ffff73bdf8d.jpg)


#### # Pivot을 맨 처음 또는 맨 마지막을 설정하는건 별로 좋지 못한 방법이다. 따라서 중간값 또는 랜덤값을 설정하자

### 구현

```c++
#include <iostream>
#include <ctime>

using namespace std;


int Quick_partition(int arr[], int start, int end){
    srand(time(NULL));
    //int p_idx = rand()%end;
    int p = arr[end]; // Pivot을 랜덤값으로 지정
    int i = start-1; //배열의 밖을 지정
    int j = start; // 시작 부분 지정

    while(j<end)
    {
    if(arr[j]>=p) 
        j = j+1;  // 기준보다 크면 그냥 넘어감 
    else{  //기준보다 작다면 값을 스왑
        i = i+1;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j = j+1;
        }
    }
    int temp = arr[i+1];  //마지막 기준값을 위치에 맞게 재배치 이후 Index를 return
    arr[i+1] = p;
    arr[end] = temp;
    return (i+1);
}

void Quick_Sort(int arr[], int start, int end){
    if(start<end){
        int pivot = Quick_partition(arr, start, end);
        Quick_Sort(arr,start, pivot-1);
        Quick_Sort(arr, pivot+1, end);
    }
}
int main(){
    int arr[] = {12,24,63,12,51,2,125,32};
    int size = 8;
    int start = 0;
    int end = size-1;
    Quick_Sort(arr,start, end);
    
    for(int i=0; i<=end; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}

```
</div>
</details>
