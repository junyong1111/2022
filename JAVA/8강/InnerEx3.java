public class InnerEx3 {
    public class InnerExam3{
        public void exec(){ //메소드 안에서 선언되는 지역 중첩 클래스
            class Cal{
                int value = 0;
                public void plus(){
                    value++;
                }
            }
            Cal cal = new Cal();
            cal.plus();
            System.out.println(cal.value);
        }


        public static void main(String args[]){
            InnerExam3 t = new InnerExam3();
            t.exec();
        }
    }    
}
