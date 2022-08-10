public class ExceptionEx {
    public class ExceptionExam{
	
        public static void main(String[] args){
            int i = 10;
            int j = 5;
            int k = i/j;
            System.out.println(k);
        }
    }
    // k의 출력값은 2로 정상 작동
    
    public class ExceptionExam{
        
        public static void main(String[] args){
            int i = 10;
            int j = 0;
            int k = i/j;
            System.out.println(k);
        }
    }
    // 0을 나누게 되면 프로그램 오류가 발생
    // Exception 발생 지점부터 프로그램 오류    
}
