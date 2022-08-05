public class ArrayEx3 {
    public static void main(String [] args){
        int [][] array = {{1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}};
    
        for(int i = 0 ; i < array.length; i++) {
            System.out.print( (i+1) + "번째 줄을 출력합니다>");
            for(int j = 0; j< array[i].length; j++) {
                System.out.print(array[i][j]+" ");
            }
            System.out.println("");
        }
    }
}
