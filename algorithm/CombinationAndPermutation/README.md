# 조합과 순열

### 순열과 조합 모두 n개에서 r개를 뽑는다는 것은 동일하지만 순열의 정의에서 '정렬'이라는 단어가 순열의 특징을 나타내는데, 순열은 순서가 있다.

# 순열 - Permutation
- n개의 공 중 r개를 뽑아 만드는 순서있는 조합
1. algorithm 헤더 함수 사용
2. DFS와 Checklist 사용


1. 가장 간단한 방법으로 algorithm 헤더에 있는 next_permutation(v.begin(), v.end())를 사용
    - do while문을 사용하여 해당 Vector의 순열을 알 수 있다.
    - 오름차순으로 정렬되어있어야 한다.
    - 중복은 제거해준다.

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int>V;
    for(int i=1; i<=3; i++){
        V.push_back(i);
    }    
    // [1,2,3]
    int count =  0; 
    
    do{
        for(auto it = V.begin(); it!=V.end(); ++it)
            cout << *it << " ";
        cout << "\n";    
        count++;
    }while(next_permutation(V.begin(), V.end()))

    cout << " Count is " << count << "\n";

    return 0;
}
```

# 조합 - Combination
- n개의 공 중 r개를 뽑아 만드는 순서없는 조합
1. algorithm 헤더 함수 사용
2. DFS와 Checklist 사용


1. 가장 간단한 방법으로 algorithm 헤더에 있는 prev_permutation(temp.begin(), temp.end())함수를 사용
    - do while문을 사용하여 해당 Vector의 조합을 알 수 있다.
    - temp vector를 사용하여 r개의 원소는 1로 만들고 나머지는 0으로 만든다
    - do 문장에서 v.size()만큼 for문을 돌면서 만약 temp[i]의 원소가 1이면 출력을 해준다
    

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;

    vector<int>V;
    for(int i=1; i<=4; i++){
        V.push_back(i);
    }
    sort(V.begin(), V.end());

    vector<int>temp(V.size(),0);
    for(int i=0; i<3; i++){
        temp[i] = 1;
    }

    do{
        for(int i=0; i<V.size(); i++){
            if(temp[i] ==1)
                cout << V[i] << " ";
        }
        answer ++;
        cout << endl;
    }while(prev_permutation(temp.begin(), temp.end()));

    cout << answer <<"\n";
    return 0;
}
```