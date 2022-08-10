
public class OverringEx {
    public class Car{
        public void run(){
            System.out.println("Car의 run메소드");
        }
    }
    
    public class Bus extends Car{
            public void run(){
                    super.run() //부모의 메소드를 호출하고 싶을때 
                    System.out.println("Bus의 run메소드");
                }
        }
    
    public static void main(String [] args){
        Bus bus = new Bus();
        Car car = new Car();
        bus.run();
        car.run();
    }    
}
