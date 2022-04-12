import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int com[] = new int[3];
        int cnt = 0;
        int len = array.length;
        for(int i=0; i<commands.length; i++){
            for(int j=0; j<commands[i].length; j++){
              com[j] = commands[i][j];
            } //command2
            int from = com[0];
            int to = com[1];
            int get = com[2];
            int temp_len = (to-from)+1;
            int temp[] = new int[temp_len];
            for(int k=1; k<=len; k++){
                int idx = 0;
                if(k==from){
                    while(temp_len!=0){
                        temp[idx++] = array[k-1];
                        from++;
                        k++;
                        cnt ++;
                        temp_len--;
                } //while 
                } //if
                else{continue;}
            }
            Arrays.sort(temp);
            for(int a=0; a<cnt; a++){
                if(a==get-1){
                     answer[i] = temp[a];
                }
                System.out.print("temp is :" + temp[a]);
            }
            System.out.println();
            
        
            cnt = 0;
        } //command1
        
        return answer;
    }
}