public class classEx {
    public static class Car{
        String name;
        int Number;

        public Car(String name){
            this.name = name;
        }
        // 객체 자신을 참조하는 this를 이용!!
    }
    
    public static void main(String [] args){
    // Car c1 = new Car();  //오류
    Car c1 = new Car("소방차");
    // Car라는 객체가 생성되면서 매개변수를 이용하여 생성되며 기본생성자는 만들어지지 않는다.
    }
}
