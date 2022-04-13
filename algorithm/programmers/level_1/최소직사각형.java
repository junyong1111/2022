import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        //w,h
        int Max_X = 0;
        int Max_Y = 0;
        for(int i=0; i<sizes.length; i++){
                Arrays.sort(sizes[i]);
                if(Max_X <= sizes[i][0]){
                    Max_X = sizes[i][0];
            }
                if(Max_Y <= sizes[i][1]){
                    Max_Y = sizes[i][1];
                }
        }
        answer = Max_X * Max_Y;
        System.out.println("Max_X의 값은 : "+ Max_X);
        System.out.println("Max_Y의 값은 : " + Max_Y);
        return answer;
    }
}