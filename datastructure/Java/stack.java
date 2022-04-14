import java.util.*;

public class stack{
    public static final int SIZE = 1000;
    public 
        char data[] = new char [SIZE];
        int point = 0;
    public stack(){
        this.point = -1;
    }

    public void init(){
        this.point = -1;
    }

    public boolean isFull(){
        if(this.point == (SIZE-1)){
            return true;
        }
        else return false;
    }

    public boolean isEmpty(){
        if(this.point == -1){
            return true;
        }
        else{
            return false;
        }
    }
    public void push(char elem){
        if(this.isFull()){
            System.out.println("This stack is Full !!!!\n");
        }
        else{
            this.point++;
            this.data[this.point] = elem;
        }
    }

    public char pop(){
        if(this.isEmpty()){
            System.out.println("This stack is Empty!!!!\n");
            return 'e';
        }
        else{
            char temp = this.data[this.point];
            this.point = this.point -1;
            return temp;
        }
    }

    public char peek(){
        if(this.isEmpty()){
            System.out.println("This stack is Empty!!!!\n");
            return 'e';
        }
        else{
            return this.data[this.point];
        }
    }

    public void print(){
        for(int i=0; i<=this.point; i++){
            System.out.print(this.data[i]+" ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        stack s = new stack();
        s.init();
        s.push('A');
        s.print();
        System.out.println(s.peek());
        System.out.println(s.pop());
    }
}

