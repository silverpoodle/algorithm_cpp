package leetcode;

import java.util.HashSet;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
       public boolean hasCycle(ListNode head) {

        HashSet<ListNode> set = new HashSet<>();

        while(head != null) {
            if(set.contains(head)) return true;

            else {
                set.add(head);
                head = head.next;
            }
        }
        return false;
       }
   }

   //todo: floyd cycle finding