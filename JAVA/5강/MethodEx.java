
public class MethodEx {
    public void method1(){ //리턴값이 없다면 void를 사용
        System.out.println("mthod1이 실행됨");
    }
    
    public void method2(int value){ //정수형 인자를 받음
        System.out.println(value + "method2가 실행됨");
    }
    
    public int method3(){
        System.out.println("method3이 실행됨");
        return 10;
    } // 리턴값을 설정했으니 리턴값을 줘야함
    
    public void method4(int x, int y){ //여러개의 인자를 받음
            System.out.println(x+y + "method4가 실행됨");
    }
    
    public int method5(int x){ //정수형 인자를 받음
            System.out.println(x + "method5가 실행됨");
            return x*2;
    } // 받은 인자를 이용하여 리턴

    public static void main(String [] args){
		MethodEx myclass = new MethodEx();
		// myclass.을 이용하여 메소드 접근가능
		myclass.method1();

		myclass.method2(10); //정수형을 무조건 넣어줘야 한다.

		int value = myclass.method3(); //리턴값을 받아낼 변수가 필요
		System.out.println(value);  //받은 값 확인

		myclass.method4(3,4); //2개의 정수값을 인자로

		int value1 = myclass.method5(10); //정수 인자를 이용하여 리턴값 받음
		System.out.println(value1); //확인
}
    
}
