import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        int cnt = 0; // 새로운 배열의 크기를 위해
        int j =0; //정답 배열의 인덱스 접근을 위한 변수
        int len = arr.length;
        
        
        for(int i=0; i<len; i++){
            if(arr[i] % divisor == 0){
                cnt++;
            }
        } // 개수체크 For
        if (cnt==0){
            int []answer = new int [1];
            answer[0] = -1;
            return answer;
        } // 나누어 떨어지는 수가 하나도 없을 경우 처리

        int []answer = new int [cnt];
        for(int i=0; i<len; i++){
            if(arr[i] % divisor == 0){
                answer[j++] = arr[i];
            }
        } // 카운터에 맞게 정답배열을 생성 후 하나씩 넣어준 후
        Arrays.sort(answer); //오름차순 정렬
        return answer;
    }
}