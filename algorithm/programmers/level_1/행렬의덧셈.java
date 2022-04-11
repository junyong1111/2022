import java.util.*;

class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int temp = 0 ;
        int len_1 = arr1.length;
        int len_2 = arr1[0].length; 
        int[][] answer = new int[len_1][len_2];
        for(int i=0; i<len_1; i++){
            for(int j=0; j<len_2; j++){
                answer[i][j]  = arr1[i][j] + arr2[i][j];         
            }
        }  
        return answer;
    }
}