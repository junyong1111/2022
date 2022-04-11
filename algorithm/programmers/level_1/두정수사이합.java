import java.util.*;

class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        if(a>=b){ // a<b 조건에 맞게 스왑
            int temp = a;
            a = b;
            b = temp;
        }
        
        for(int i =a; i<=b; i++){
            answer = answer + i;
        }
        return answer;
    }
}