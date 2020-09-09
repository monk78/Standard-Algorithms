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
    static Node reverseBetween(Node headx,int m,int n){
        if(headx==null)return null;
        Node curr=headx,prev=null;
        while(m>1){
            prev=curr;
            curr=curr.next;
            m--;
            n--;
        }
        Node con=prev,tail=curr;
        Node third=null;
        while(n>0){
            third=curr.next;
            curr.next=prev;
            prev=curr;
            curr=third;
            n--;
        }
        if(con!=null){
            con.next=prev;
        }
        else {
            headx=prev;
        }
        tail.next=curr;
        return headx;
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
        Node ans2=methodclass.RevK(list.head,3);
        System.out.println();
        new LinkedList().print(ans2);
        System.out.println();
        Node ans3=methodclass.reverseBetween(ans2,1,3);
        new LinkedList().print(ans3);
    }
}
/*
1 2 3 4 5 
5 4 3 2 1 
3 4 5 1 2 
5 4 3 1 2 

*/
