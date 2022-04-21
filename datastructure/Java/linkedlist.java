import java.util.*;

public class linkedlist{
    private class Node{
        int data;
        Node next;
    }
    public Node Head;

    public linkedlist(){
        this.Head = null;
    }

    public void insertFirst(int elem){
        Node node = new Node();

        node.data= elem;
        node.next = this.Head;
        this.Head = node;
    }

    public void insert(int elem, int pos){
        Node node = new Node();
        Node point = new Node();
        int cnt = 0;
        point = this.Head;
        for(; point!=null; point =point.next){
            cnt ++;
        }
        if(cnt<pos){
            System.out.println("POS EORROR");
            return ;
        }
        point = this.Head;


        if(pos==1){
            //this.insertFirst(elem);
            insertFirst(elem);
        }
        else{
            for(int i=1; i<pos-1; i++){
                point = point.next;
            }
            node.data = elem;
            node.next = point.next;
            point.next = node;
        }


    }

    public void print(){
        Node p = new Node();
        p = this.Head;
        while(p!=null){
            System.out.println(p.data);
            p = p.next;
        }
    }
    public static void main(String[] args){
        linkedlist DL = new linkedlist();
        DL.insertFirst(10);
        DL.insert(60, 2);
        DL.insert(70, 3);
        DL.insert(50, 1);
        // DL.insertFirst(20);
        // DL.insertFirst(30);
        // DL.insertFirst(40);
        // DL.insert(50, 1);
        // DL.insert(60, 2);
        // DL.insert(70, 3);
        DL.print();
        
        
        
    }
}