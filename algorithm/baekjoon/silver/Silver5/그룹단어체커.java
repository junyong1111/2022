import java.util.*;
class Main {
  public static void main(String[] args) {
   Scanner sc = new Scanner(System.in);
    int testCase;
    int check = 0;
    int cnt = 0;
    testCase = sc.nextInt();
    int temp =testCase;
    while(temp!=0){
        int alpha[] = new int [26]; // 알파벳을 체크하기 위한 알파벳 변수
        String str = sc.next(); 
        int len = str.length(); 
        check = 0; //연속된 문자를 확인하기 위한 변수
        for(int i=0; i<len; i++){
            if(alpha[str.charAt(i)-97]==0){    //만약 처음 나온 문자라면 알파벳배열의 값을 1로 
                 alpha[str.charAt(i)-97] = 1; 
                 check = str.charAt(i); // 연속문자를 확인하기 위해 check 변수에 알파벳 값을 넣어줌
            }
            if(check == str.charAt(i)){ //연속된 문자면 넘어감
                continue;
            }
            else{  // 알파벳 배열의 값도 1이면서 연속된 문자도 아니라면 중복된 문자가 나중에 나온 경우이므로 카운트를 1올려주고 멈춰줌
                cnt++;
                break;
            }
        }
        temp--;
    }
    int sum = testCase - cnt ; //총 단어의 개수 - 중복된 횟수 = 정답!
    sc.close();
    System.out.println(sum);
        
  }
}