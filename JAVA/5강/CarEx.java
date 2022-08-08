public class CarEx{
    public static class Car{
        String name;
        int number;
    }
	public static void main(String[] args){
        Car c1 = new Car();
        Car c2 = new Car();
        
        c1.name = "소방차";
        c1.number = 1234;
    
        c2.name = "구급차";
        c2.number = 1111;
    // 자동차 객체를 생성한 후 속성 값 삽입
    
        System.out.println(c1.name);
        System.out.println(c1.number);
    // c1 객체 확인
        System.out.println(c2.name);
        System.out.println(c2.number);
    // c2 객체 확인
    }
}