public class Try_catchEx {
    public class ExceptionExam{
	
        public static void main(String[] args){
            int i = 10;
            int j = 0;
            try{
                int k = i/j;
                System.out.println(k);
            }
    
            catch(ArithmeticException e){
                System.out.println("0으로 나눌 수 없습니다."+e.toString());
            } // toString 메소드는 예외에 대한 정보를 알려줌
    
            finally{
                System.out.println("오류가 발생하든 발생하지 않든 무조건 실행");
            }
            System.out.println("main ent!!");
        }
    } 
}
