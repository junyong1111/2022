public class abstactEx {
    public static abstract class Bird{
        public abstract void sing(); //각각 새마다 울음소리가 다르다.
        public void fly(){
            System.out.println("날다");
        }
    }
    
    public static class Duck extends Bird{
        @Override
        public void sing(){
            System.out.println("꽥꽥");
        } // 추상 클래스에서 상속받은 추상메소드 sing을 구현해야 함.
    }
    
    public static void main(String [] args){
        Duck duck = new Duck();
        duck.sing();
        duck.fly();
        
    //	Bird bird = new Bird(); // 추상클래스는 객체로 생성할 수 없다.
    }
}