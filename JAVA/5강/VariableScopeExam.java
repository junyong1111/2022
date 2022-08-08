public class VariableScopeExam{
	int globalscope = 10;
	static int staticValue = 10;
	
	public void scopeType1(int value){
		int localscope =20;
		globalscope = value; //가능
		localscope = 40; //가능
	}
	
	public void scopeType2(int value){
		globalscope = value; //가능
		localscope = 40; //불가능
	}
	
	public static void main(String[] args){
		globalscope = 100; //불가능
		localscope = value; //불가능
		staticValue = 20 // 가능
	
		VariableScopeExam v1 =new VariableScopeExam();
		VariableScopeExam v2 =new VariableScopeExam();
		v1.globalscope = 100; 
		v2.globalscope = 200;
	// 위처럼 객체를 생성해서 사용해야 하며 각각 다른객체 이므로 다른값이 들어간다.
		v1.staticValue = 100;
		v2.staticValue = 200;
	// static 필드는 값을 공유하므로 두 객체는 같은값을 가지고 있다.
	}
}