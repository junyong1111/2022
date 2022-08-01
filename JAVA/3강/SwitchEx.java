package 3강;

public class switchEx {
    public static void main(String[] args){
        int num = 1;
        int num1 = 0;
        int num2 = 0;

        switch(num){
            case 1 : num1 = num;
                    break;
            case 2 : num2 = num;
                    break;
            default : num = num;
        }
    }
}
