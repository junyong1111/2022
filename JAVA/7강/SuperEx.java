public class SuperEx {
    public static class Car{
        /*	public Car(){
                System.out.println("Car의 기본생성자");
            }
        */  //기본생성자의 경우
        
        
            public Car(String name){
                System.out.println("Car의 생성자");
            }
        }
        // 기본생성자가 아닌경우
        
        public static class Truck extends Car{
            public Truck(){
                // super(); //부모의 생성자를 이야기함 직접 부르지않아도 자동으로 불러진다.
                super("소방차"); // 부모의 기본생성자가 없는경우 생성자에 맞게 호출해줘야 한다.
                System.out.println("Trcuk의 기본생성자");
            }
        }
        
        public static void main(String [] args){
            Truck truck  = new Truck();
        // 이때 Car의 기본생성자와 트럭의 기본생성자가 실행된다.
        }
}
