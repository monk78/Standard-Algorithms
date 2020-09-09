/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy=new ListNode(0);
        ListNode curr=dummy;
        ListNode temp=head;
        
        while(temp!=null){
            if(temp.val<x){
                ListNode xx=new ListNode(temp.val);
                curr.next=xx;
                curr=xx;
            }
            temp=temp.next;
        }
        
        ListNode temp2=head;
        while(temp2!=null){
            if(temp2.val>=x){
                ListNode xx=new ListNode(temp2.val);
                curr.next=xx;
                curr=xx;
            }
            temp2=temp2.next;
        }
        
        return dummy.next;
    }
}
