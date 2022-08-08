public class ExString {
    public static void main(String[] args){
    String str = "Hello";
    str.length(); // 문자열의 길이를 반환해주며 공백도 하나의 문자로 인식한다.
    str.concat(" World"); // 문자열을 더해준다 -> Hello World
    /* 
        이때 str을 확인해보면 Hello World가 아닌 Hello로 나온다. 
        즉 concat을 사용하면 새롭게 생성한 String Hello World를 반환하다.
    */
    str = str.concat(" World"); // 이 처럼 사용해야 str값이 변환된다.

    str.substring(3); //3번 인덱스부터 잘라준다.
    str.substring(3,6); // 3번부터 6번까지 인덱스를 잘라준다.    
    }
}
