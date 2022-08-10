public class ThrowsEx {
    public class ExceptionExam2 {
	
        public static void main(String[] args){
            int i = 10;
            int j = 0;
            int k = divide(i,j);
            System.out.println(k);
        }
    // ----------------- 오 류 코 드 -------------------
        public static int divide(int i, int j) throws ArithmeticException{
            int k = i/j;
            return k;
        } // (throws 발생 할 Exception)은 이 메소드 안에서 발생하는 어떤 오류든 처리 가능
    
    }
    // ----------------- 해 결 방 법 -------------------
        public static void main(String[] args){
            int i = 10;
            int j = 0;
            try{
                int k = divide(i,j);
                System.out.println(k);
            }
            catch(ArithmeticException e){
                System.out.println(e.toString());
            }
        }
    // ----------------- 해 결 코 드 -------------------
}
