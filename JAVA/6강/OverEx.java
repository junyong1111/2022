public class OverEx1 {
    public static class Car{
        String name;
        int Number;
    public Car(){
        //this.name = "이름없음"
        //this.Number = 0;
        this("이름없음", 0); 
    // 아래에 있는 생성자를 이용하여 초기화 가능
    
    } //기본 생성자 오버로딩
    
    public Car(String name, int Number){
        this.name = name;
        this.Number = Number;
    } // 생성자 오버로딩
    }

    public static void main(String [] args){
        Car c1 = new Car();
    }
}
