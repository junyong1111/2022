public class ThrowsClassEx {
    public class BizException extends RuntimeException{
        super(msg);
    }
    public BizException(Exception ex){
        super(ex);
    }
    // 문자열로된 오류메세지와 실제 발생 할 Exception을 담는 목적의 생성자 두 개 선언 
    // 이미 부모 class가 같은 기능을 가진 생성자가 있기 때문에 사용자가 정의한 Exceptiom개체에서 따로 할 것은 해당 생성자를 부모의 생성자에게 전달만 시켜주면 된다. (super 메소드 사용)
    
    // ----------- 사용자 정의 Exception 정의 -----------
    public class BizService{
        public void bizMethod(int i) throws BizException{
            System.out.println("비지니스 메소드 시작");
            
            if(i < 0)
                    throw new BizException("매개변수 i는 0 이상이어야 합니다.");
    
            System.out.println("비지니스 메소드 종료");
        }
    }
    // ----------- Exception을 발생시켜주는 코드 -----------
    public class BizExam{
        public static void main(String[] args){
            BizService biz = new BizService();
            biz.bizMethod(5); // 정상 작동
            try{
                biz.bizMethod(-3); // 0보다 작은 값에선 Exception 발생
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
    }
    // ----------- Exception을 사용하는 class 코드 -----------    
}
