## Hash

- 전화번호 목록 (Level_2) 

### 해쉬 테이블을 이용하여 구현하는 문제이다. 쉽게 생각할 수 있는 방법으로 구현한다면 테스트케이스는 맞더라도 효율성 문제에 걸린다. 해쉬 테이블에 대한 기본적인 이해가 필요하다.

### 실패코드

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool com(string a, string b){
    return a.length()<b.length();
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), com);
    
    string temp;
    
    for(int i=0; i<phone_book.size(); i++){
        temp = phone_book[i];
        bool check = false;
        
        int len = temp.length();
        for(int j= i+1; j<phone_book.size(); j++){
            for(int k=0; k<len; k++){
                if(temp[k] == phone_book[j][k])
                    check = true;
                else{
                    check = false;
                    break;
                } 
            }
            if(check == true){
                return false;
            }
            
        }
    }
    answer = true ;
    
    return answer;
}
```

### 성공

최초 최소길이를 계산 후 최소길이만큼만 비교해주는 방식으로 해결했다. 이 때 주의할 점은 최소길이는 같지만 접두어가 다른경우가 발생할 수 있어서 한 번 더 확인하는 과정이 필요하다.


- 위장 (Level_2) 

### 해쉬 테이블을 이용하여 구현하는 문제이다. 수학적 수식을 생각하는게 조금은 어려웠던 문제이지만 패턴을 찾는다면 쉽게 해결 가능하다.