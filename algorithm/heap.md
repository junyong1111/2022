### **이진 Heap**이라는 **자료구조**를 이용하여 정렬하는 방법으로 시간복잡도가 O(Nlog2N)으로 상당히 빠른속도의 정렬이 가능하며 추가배열이 필요하지 않아 저장공간을 적게 차지한다는 장점이 있다.

### Heap ?  
Heap이 되기위해서는 2가지 조건이 필요하다.
1. Complete binary tree
2. Heap property를 만족

**첫 번째로는 Complete binary tree이다.**   
Complete binary tree(계층적관계)
- Full binary tree : 모든 Level의 Node가 꽉 차있는 형태
-  Complete binary tree : 마지막 Level을 제외하고 모든 Node가 다 있으며 마지막 Level에서 오른쪽부터 노드가 없을 수 있다.

#### # Root node: Tree의 제일 윗 부분
#### # Leaf node: 자식이 없는  마지막 level Node

#### # binary tree(이진트리) : 각각의 Node가 최대 2명의 자식을 가질 수 있다.

#### # Full binary tree는 Complete binary tree조건도 만족


![IMG_0417](https://user-images.githubusercontent.com/79856225/164885793-5fa60bbe-e8df-4565-962a-8ddfe6a110e1.jpg)

**두 번째로는 Heap property만족이다**  
Heap property(힙의 특성) 다음 중 하나를 만족해야 한다.
- Max Heap Property 
    - 부모노드는 자식노드보다 **크거나 같다**
- Min Heap Property
    - 부모노드는 자식노드보다 **작거나 같다**

**Heap**은 **Complete binary tree** 이면서 **Max Heap property** 또는 **Min Heap property**를 만족하면 된다.

### Heap의 1차원 배열로 표현

다음과 같은 조건으로 힙을 1차원 배열로 표현을 할 수 있다.

- 루트 노드 : Arr[1]
- Arr[i]의 부모 노드 : Arr[i/2]
- Arr[i]의 왼쪽 자식 : Arr[2*i]
- Arr[i]의 오른쪽 자식 : Arr[(2*i)+1]

1. 정렬할 데이터를 Complete binary tree로 생각  
-> 아직 Heap이 아님 따라서  Heap특성을 만족시켜야 함  
##### # 현재 예제에서는 MAX특성을 이용 MIN또한 구현 가능

2. MAX_HEAPIPY()을 이용하여 Heap특성을 만족시킴  
두 가지 방법이 존재
    - Recursive Version  
        - Base case :   Arr[i] 의 자식 노드가 없을 때
        - Recursive Case : i 의 자식노드 중에서 최댓값 K를 찾고 Arr[i] 부모노드와 Arr[K] 최대 자식노드를 Swap
        MAX_HEAPIPY(Arr, K) 

    - Iteractive Version  
    While -> Arr[i]의 자식노드가 있는동안  
    i의 자식노드의 Max 값을 찾아 -> K 삽입  
    Arr[i] 부모노드와 Arr[K] 최대 자식노드를 Swap  


![IMG_0417 2](https://user-images.githubusercontent.com/79856225/164886386-9e343158-8db6-444c-b0fc-1a6da2431d45.jpg)

### MAX_HEAPIPY 구현

```c++
int Arr = [12,24,63,14,51,2,125,32]
```
입력받은 배열

    



