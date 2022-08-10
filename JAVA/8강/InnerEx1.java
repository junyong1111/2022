public class InnerEx1 {
    public class InnerExam{
        class Cal{ //중첩 클래스 
                            int value = 0;
                public void plus(){
                value++;
                }
        }
    }
    
    public static void main(String [] args){
        InnerExam ex = new InnerExam(); //상위 클래스를 미리 선언
        InnerExam.Cal cal = new ex.new Cal();
        cal.plus();
    }
}
