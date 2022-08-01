public class ByteVariable {
    public static void main(String[] args){
        byte bData = -128;
        System.out.println(bData);

        // byte bData2 = 128; 128은 표현이 불가능
        byte bData2 = 127; //바이트가 표현할 수 있는 수는 127이 끝이다.
        System.out.println(bData2);
    }
}
