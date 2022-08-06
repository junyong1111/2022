public class EnumEx{
	public static final String MALE ="MALE";
	public static final String FEMALE ="FEMALE";
	
	public static void main(String [] args){
		String gender1; //MALE 과 FEMAL 둘 중 하나의 값을 넣고싶음
		gender1 = EnumEx.MALE;
		gender1 = EnumEx.FEMALE;
		gender1 = "boy"; //하지만 다른 string 값이 들어와도 오류를 발생시키지 않는다.
	
		Gender gender2;
		gender2 = Gender.MALE;
		gender2 = Gender.FEMALE;
		gender2 = "boy"; //에러 
	}
enum Gender{
		MALE,FEMALE; 
	}
}