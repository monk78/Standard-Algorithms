//definations of LinkedList and Node are there in CycleDetection.java
class methodclass{

    static LinkedList Rev(LinkedList list){
        Node curr=list.head;
        Node prev=null;
        Node next=null;
        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        list.head=prev;
         return list;
   }
   static Node RevK(Node head,int k){
        Node curr=head;
        Node prev=null;
        Node next=null;
        int cnt=0;
        while(cnt<k && curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(next!=null){
            head.next=RevK(next,k);
        }
        return prev;
   }
};
public class ReverseAndMore {
    public static void main(String[] args) {
        LinkedList list=new LinkedList();
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        list.printlist();
        System.out.println();
        LinkedList ans=methodclass.Rev(list);
        ans.printlist();
        Node ans2=methodclass.RevK(list.head,2);
        System.out.println();
        new LinkedList().print(ans2);
    }
}
/*
1 2 3 4 5 
5 4 3 2 1 
4 5 2 3 1 


*/
