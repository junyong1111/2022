public class ArrayEx2 {
    public static void main(String [] args){
        int [][] arr = new int[3][4];
        // arr[0] = 4; 오류 발생 정확하게 인덱스를 다 표현해줘야 한다.
        arr[0][1] = 10; 


        int [][] arr1 = new int[3][];
        arr1[0][0] =10; // 불가능
        arr1[0] = new int[10]; 

        
    }    
}
