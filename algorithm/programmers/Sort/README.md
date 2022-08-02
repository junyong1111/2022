## 정렬

- K번째수 (Level_1)

### 문제에서 주어진 조건에 맞게 벡터를 복사 후 정렬하며 쉽게 해결이 가능한 문제이다.

- 가장 큰 수 (Level_2)

### 테스트 케이스는 모두 통과하였지만 채점 결과는 참담하다... 어떤식으로 해결해야할지... 

### 실패 코드
```c++
//실패 코드
#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(vector<int> numbers) {
    int size = numbers.size();
    string answer = "";
    int max = 0;
    int index = 0;
    vector<string>str;
    for(auto n : numbers){
        str.push_back(to_string(n));
    }
    
    
    for(int i=0; i<size-1; i++){
        max = str[i][0]; //제일 앞에 있는 원소
        for(int j=i+1; j<size; j++){
            int idx = 1;
            if(max<str[j][0]){
                max = str[j][0];
                index = j;    
            } 
            else if(max ==str[j][0]){
                while(str[i][idx]!=NULL && str[j][idx]!=NULL){
                    if(str[i][idx] == str[j][idx])
                        idx++;
                    else{
                        index = str[i][idx] > str[j][idx]?i:j;
                        break;
                    }
                }
                if(str[i][idx] == NULL){
                    char temp = str[i][idx-1];
                    while(1){
                        if(temp == str[j][idx]){
                            idx++;
                        }
                        else break;
                    }
                    index = temp>str[j][idx]?i:j;
                    
                }else if (str[j][idx] == NULL){
                    char temp = str[j][idx-1];
                    while(1){
                        if(temp == str[i][idx]){
                            idx++;
                        }
                        else break;
                    }
                    index = str[i][idx]>str[j][idx-1]?i:j;
                }
            } // 같은값이 나온 경우   
        }
        answer = answer + str[index];
        swap(str[i], str[index]);
    }
    answer =answer + str[size-1];
    if(answer[0]=='0'){
        answer = "0";
    }    
    // for(auto s: str){
    //     cout << s << " ";
    // }
    
    
    return answer;
}
```

### 성공
- 단순하게 string 값을 더하는 조건식을 세우면 되는거였는데 너무 복잡하게 생각하려고 했다....
ex)  [30, 3] -> a+b = 303 , b+a = 330 으로 쉽게 식을 세울 수 있었음..


- H-index (Level_2)

### 알고리즘만 잘 구현한다면 어렵지 않게 해결이 가능하다 단, 조건에서 주어진 h가 배열안에 있는 숫자가 아니고 1개씩 커지는 숫자다..함정 조심

