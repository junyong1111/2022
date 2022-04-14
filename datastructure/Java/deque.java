import java.util.*;

public class deque{
    public static final int SIZE = 1000;

    public
        char data[] = new char [SIZE];
        int front ;
        int rear;
    public deque(){
        this.front = -1;
        this.rear = SIZE;
    }
    public void init(){
        this.front = -1;
        this.rear = SIZE;
    }

    public boolean isFull(){
        if(this.rear == (this.front+1)%SIZE){
            return true;
        }
        else{
            return false;
        }
    }

    public boolean isEmpty(){
        if(this.front == (this.rear+1)%SIZE){
            return true;
        }
        else{
            return false;
        }
    }

    public void enqueFirst(char elem){
        if(isFull()){
            System.out.println("This deque is FULL !!!!!");
        }
        else{
            this.front = (this.front+1) % SIZE;
            this.data[this.front] = elem;           
        }
    }
    public void enqueLast(char elem){
        if(isFull()){
            System.out.println("This deque is FULL !!!!!");
        }
        else{
            this.rear = (this.rear-1) % SIZE;
            this.data[this.rear] = elem;
        }
    }
    public char dequeFirst(){
        if(isEmpty()){
            System.out.println("This deque is EMPTY !!!!!");
            return 'e';
        }
        else{
            char temp = this.data[this.front];
            this.front = (this.front-1) % SIZE;
            return temp;
        }
    }

    public char dequeLast(){
        if(isEmpty()){
            System.out.println("This deque is EMPTY !!!!!");
            return 'e';
        }
        else{
            char temp = this.data[this.rear];
            this.rear = (this.rear+1) % SIZE;
            return temp;
        }
    }

    public char peekFirst(){
        if(isEmpty()){
            System.out.println("This deque is EMPTY !!!!!");
            return 'e';
        }
        else{
            char temp = this.data[this.front];
            return temp;
        }
    }
    public char peekLast(){
        if(isEmpty()){
            System.out.println("This deque is EMPTY !!!!!");
            return 'e';
        }
        else{
            char temp = this.data[this.rear];
            return temp;
        }
    }

    public void print(){
        for(int i=0; i<=this.front; i++){
            System.out.print(this.data[i]+ " ");
        }
        for(int i=this.rear; i<SIZE; i++){
            System.out.print(this.data[i]+ " ");
        }
        System.out.println();
}
    public static void main(String[] args){
        deque DE = new deque();
        DE.enqueFirst('A');
        DE.enqueFirst('B');
        DE.enqueFirst('C');
        DE.print();
        DE.enqueLast('F');
        DE.enqueLast('E');
        DE.enqueLast('D');
        DE.print();
        System.out.println("[" + DE.dequeLast() + "] is deleted!!");
        System.out.println("[" + DE.dequeFirst() + "] is deleted!!");
        DE.print();
        System.out.println("[" + DE.dequeLast() + "] is deleted!!");
        System.out.println("[" + DE.dequeFirst() + "] is deleted!!");
        DE.print();
    }
}