public class ExtendsEx {
    public class Car{
        public void run(){
            System.out.println("달리다");
        }
    } //기존의 Car클래스
    
    public class Bus extends Car {
        public void ppangppang(){
            System.out.println("빵빵");
        }
    }
    
    public static void main(String [] args){
        Bus bus = new Bus();
        bus.run(); 
        bus.ppangppang();
    // Bus클래스에는 run 메소드가 없지만 Car 클래스를 상속받았으므로 Car의 run메소드 사용가능.
    // 뿐만 아니라 자신의 메소드도 사용가능하다 
        Car car = new Car();
        car.run();
        car.ppangppang(); //오류
    // 부모 클래스인 Car는 자신의 메소드인 run()메소드는 사용가능하지만 자식의 메소드는 사용이 불가능하다/
    }    
}
