import java.util.*;

public class queue{
    public static final int SIZE = 1000;
    public 
    char data[] = new char[SIZE];
    int front, rear;

    public queue(){
        this.front = 0;
        this.rear = 0;
    }
    public void init(){
        this.front = 0;
        this.rear = 0;
    }
    public boolean isFull(){
        if(this.rear == (this.front+1) %SIZE){
            return true;
        }
        else{
            return false;
        }
    }
    public boolean isEmpty(){
        if(this.front == this.rear){
            return true;
        }
        else{
            return false;
        }
    }

    public void enqueue(char elem){
        if(isFull()){
            System.out.println("This Queue is Full!!!");
        }
        this.data[this.front] = elem;
        this.front = (this.front+1) % SIZE;
    }

    public char dequeue(){
        if(isEmpty()){
            System.out.println("This Queue is Empty!!!");
            return 'e';
        }
        else{
            char temp = this.data[this.rear];
            this.rear = (this.rear+1) % SIZE;
            return temp;
        }
    }
    public char peek(){
        if(isEmpty()){
            System.out.println("This Queue is Empty!!!");
            return 'e';
        }
        else{
            char temp = this.data[this.rear];
            return temp;
        }
    }

    public void print(){
        for(int i=this.rear; i<=this.front; i++){
            System.out.print(this.data[i]+" ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        queue Q = new queue();
    }
}