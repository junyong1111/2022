## 스택/큐

- 같은숫자는싫어 (Level_1)

### 스택을 이용하여 구현 기본적인 스택문제

- 기능개발 (Level_2)

###  큐를 이용하여 구현하는 문제이며 끝나는 시간을 큐의 넣고 비교해가면서 풀면 쉽게 풀 수 있다.

- 프린터 (Level_2)

###  큐를 이용하여 구현하는 문제이며 구조체를 이용하여 비교해야하는 문제이고 기본문제보다는 약간의 응요이 필요한 문제이다.

- 올바른 괄호 (Level_2)

###  스택을 이용하여 구현하는 문제이며 스택의 기본문제라고 볼 수 있다. 어렵지 않게 해결 가능하다.

- 주식가격 (Level_2)

###  스택과 큐를 이용하여 구현하는 문제인데 사용하지않고도 해결가능 어려운 문제는 아닌듯하다.

- 다리를 지나는 트럭 (Level_2)

###  큐를 이용하는 문제처럼 보이는데 구현이 쉽지않다 실패원인을 찾아야함

### 실패코드
```c++
//실패 코드 ... 뭐가 잘못된걸까

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    int len = bridge_length;
    
    
    
    for(int i=0; i<truck_weights.size()-1; i++){
        int temp = truck_weights[i] + truck_weights[i+1];
        if(temp <= weight){
            answer ++;
        }
        else{
            answer = answer + len;
        }
    }
    
    answer = answer + len;
    
    
    return answer;
}
```
