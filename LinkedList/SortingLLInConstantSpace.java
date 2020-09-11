/*
  Merge-Sort
 Time complexity:[O(NlogN)]
 Space complexity:[O(1)]
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(){};
    ListNode(int dx){
        val=dx;
        next=null;
    }
    static ListNode append(ListNode head,int d){
        ListNode newnode=new ListNode(d);
        ListNode temp=head;
        if(temp==null){
            head=newnode;
            return head;
        }
        while(temp.next!=null)temp=temp.next;
        temp.next=newnode;
       return head;
    }
    static void print(ListNode head){
        ListNode temp=head;
        while(temp!=null) {
            System.out.print(temp.val+" ");
            temp = temp.next;
        }
    }
};

class Solution{
  ListNode tail=new ListNode();
  ListNode nextsubList=new ListNode();

    public ListNode sortList(ListNode head){
        if(head==null || head.next==null)return head;
        int n=getCount(head);
        ListNode start=head;
        ListNode dummyhead=new ListNode();
        for(int size=1;size<=n;size=size*2){
            tail=dummyhead;
            while(start!=null){
                if(start.next==null){
                    tail.next=start;
                    break;
                }
                ListNode mid=split(start,size);
                merge(start,mid);
                start=nextsubList;
            }
            start=dummyhead.next;
        }
        return dummyhead.next;
    }

  int getCount(ListNode head){
      int cnt=0;
      ListNode temp=head;
      while(temp!=null){
          temp=temp.next;
          cnt++;
      }
      return cnt;
  }
  void merge(ListNode list1,ListNode list2){
      ListNode dummyHead=new ListNode();
      ListNode newTail=dummyHead;
      while(list1!=null && list2!=null){
          if(list1.val<list2.val){
              newTail.next=list1;
              list1=list1.next;
              newTail=newTail.next;
          }
          else{
              newTail.next=list2;
              list2=list2.next;
              newTail=newTail.next;
          }

      }
      newTail.next=(list1!=null)?list1:list2;
      while(newTail.next!=null)newTail=newTail.next;
      tail.next=dummyHead.next;
      tail=newTail;
  }
ListNode split(ListNode start,int size){
      ListNode midprev=start;
      ListNode end=start.next;
      for(int index=1;index<size && (end!=null || end.next!=null);index++){
          if(end.next!=null){
              end=(end.next.next!=null)?end.next.next:end.next;
          }
          if(midprev.next!=null)midprev=midprev.next;
    }
    ListNode mid=midprev.next;
    midprev.next=null;
    nextsubList=end.next;
    end.next=null;
    return mid;
}


};



public class Main {

    public static void main(String[] args) {
	  ListNode head=null;
	  head=ListNode.append(head,2);
	  head=ListNode.append(head,6);
	  head=ListNode.append(head,5);
	  head=ListNode.append(head,1);
	  head=ListNode.append(head,8);
	  head=ListNode.append(head,3);
	  ListNode.print(head);
	  System.out.println();
	  ListNode.print(new Solution().sortList(head));
    }
}
