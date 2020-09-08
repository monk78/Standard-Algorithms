class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
};
class LinkedList{
  Node head;
  public void push(int d){
      Node newnode=new Node(d);
      if(head==null)head=newnode;
      else{
          newnode.next=head;
          head=newnode;
      }
  }
  public void append(int d){
      Node newnode=new Node(d);
      Node temp=head;
      if(temp==null){
          head=newnode;
          return;
      }
      while(temp.next!=null)temp=temp.next;
      temp.next=newnode;
  }
  //floyd cycle detection algorithm
  public boolean detectLoop(){
      Node slow=head,fast=head;
      while(slow!=null && fast!=null && fast.next!=null){
          slow=slow.next;
          fast=fast.next.next;
          if(slow==fast) {
              int x=lengthOfLoop(fast);
              System.out.println("length of loop is "+x);
              return true;

          }
         // System.out.println("cc");
      }
      return false;
  }
  public int lengthOfLoop(Node slow){
      int cnt=1;
      Node temp=slow;
      while(temp.next!=slow){
          cnt++;
          temp=temp.next;
      }
     return cnt;
  }
  public void printlist(){
      Node temp=head;
      while(temp!=null){
          System.out.print(temp.data+" ");
          temp=temp.next;
      }
  }
};

public class CycleDetection {
    public static void main(String[] args) {
	   LinkedList list=new LinkedList();
	   list.append(1);
	   list.append(2);
	   list.append(3);
	   list.append(4);
	   list.append(5);
	   list.head.next.next.next.next.next=list.head.next;
	   boolean flag=list.detectLoop();
	   if(flag==true){
           System.out.println("Yup there is a loop");
       }
	   else{
           System.out.println("no loop");
       }
	   //list.printlist();
    }
}
