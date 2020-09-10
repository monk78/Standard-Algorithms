class ListNode{
    int val;
    ListNode next;
    ListNode(int d){
        val=d;
        next=null;
    }
};
class LinkedListX{
    ListNode head;
    public void push(int d){
        ListNode newnode=new ListNode(d);
        if(head==null)head=newnode;
        else{
            newnode.next=head;
            head=newnode;
        }
    }
    public void append(int d){
        ListNode newnode=new ListNode(d);
        ListNode temp=head;
        if(temp==null){
            head=newnode;
            return;
        }
        while(temp.next!=null)temp=temp.next;
        temp.next=newnode;
    }
    void print(){
        ListNode temp=head;
        while(temp!=null){
            System.out.print(temp.val+" ");
            temp=temp.next;
        }
    }
};

class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int d){
      left=null;
      right=null;
      val=d;
  }
    TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
          this.left = left;
           this.right = right;
      }
};
class Tree{
    TreeNode root;
    public void print(TreeNode rootx){
      if(rootx==null)return;
        System.out.print(rootx.val+" ");
      print(rootx.left);
      print(rootx.right);
    }

}
class Solution{
    public TreeNode toBST(ListNode head,ListNode tail){
        if(head==tail)return null;
        ListNode fast=head;
        ListNode slow=head;
        while(fast!=tail && fast.next!=tail){
            fast=fast.next.next;
            slow=slow.next;
        }
        TreeNode thead=new TreeNode(slow.val);
        thead.left=toBST(head,slow);
        thead.right=toBST(slow.next,tail);
        return thead;
  }
  public TreeNode sortedListToBST(ListNode head){
      if(head==null) return null;
      return toBST(head,null);
  }

}

public class LinkedListToBst{
    public static void main(String[] args) {
        LinkedListX list = new LinkedListX();
        list.append(-10);
        list.append(-3);
        list.append(0);
        list.append(5);
        list.append(9);
        list.print();
        TreeNode ans=new Solution().sortedListToBST(list.head);
        System.out.println();
        new Tree().print(ans);
    }
}
