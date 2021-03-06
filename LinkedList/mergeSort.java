//definations of LinkedList and Node are there in CycleDetection.java
class Merge{
    static Node mergeSort(Node head){
        Node h=head;
        if(h==null || h.next==null)return h;
        Node middle=getMiddle(head);
        Node nexthead=middle.next;
        middle.next=null;
        Node left=mergeSort(h);
        Node right=mergeSort(nexthead);
        Node sorted=sortedMerge(left,right);
        return sorted;
    }
    static Node getMiddle(Node head){
      if(head==null)return head;
      Node slow=head,fast=head;
      while(fast.next!=null && fast.next.next!=null) {
          slow = slow.next;
          fast = fast.next.next;
      }
        return slow;
    }
    static Node sortedMerge(Node left,Node right){
        Node result=null;
        if(left==null)return right;
        if(right==null)return left;
        if(left.data<=right.data){
            result=left;
            result.next=sortedMerge(left.next,right);
        }
        else{
            result=right;
            result.next=sortedMerge(left,right.next);
        }
        return result;
    }
};
public class mergeSort {
    public static void main(String[] args) {
        LinkedList list=new LinkedList();
        list.append(3);
        list.append(4);
        list.append(5);
        list.append(1);
        list.append(2);
        list.print(list.head);
        System.out.println();
        Node hx=Merge.mergeSort(list.head);
        list.print(hx);
    }
}
/*
 3 4 5 1 2 
 1 2 3 4 5 

*/
