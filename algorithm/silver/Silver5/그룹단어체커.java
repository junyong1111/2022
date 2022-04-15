import java.util.*;
class Main {
  public static void main(String[] args) {
   Scanner sc = new Scanner(System.in);
    int testCase;
    int check = 0;
    int cnt = 0;
    testCase = sc.nextInt();
    int temp =testCase;
    while(testCase!=0){
        int alpha[] = new int [27];
        String str ;
        str = sc.nextLine();
        int len = str.length(); 
        check = 0;
        for(int i=0; i<len; i++){
            if(alpha[str.charAt(i)-97]==0){   
                 alpha[str.charAt(i)] = 1;
                 check = str.charAt(i);
            }
            if(check == str.charAt(i)){
                continue;
            }
            else{
                cnt++;
                break;
            }
        }
        testCase--;
    }
    int sum = temp - cnt ;
    System.out.println(sum);
        
  }
}