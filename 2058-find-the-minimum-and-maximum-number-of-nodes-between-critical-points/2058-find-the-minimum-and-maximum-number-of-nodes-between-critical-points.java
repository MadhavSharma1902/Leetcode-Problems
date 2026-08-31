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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int first = -1, prevCrit = -1;
        int minDist = Integer.MAX_VALUE, maxDist = -1;

        int idx = 1;
        ListNode prev = head, cur = head.next;

        while (cur != null && cur.next != null) {
            if ((cur.val > prev.val && cur.val > cur.next.val) ||
                (cur.val < prev.val && cur.val < cur.next.val)) {

                if (first == -1) {
                    first = idx;
                } else {
                    minDist = Math.min(minDist, idx - prevCrit);
                    maxDist = idx - first;
                }
                prevCrit = idx;
            }

            prev = cur;
            cur = cur.next;
            idx++;
        }

        if (prevCrit == -1 || first == prevCrit) return new int[]{-1, -1};
        return new int[]{minDist, maxDist};
    }
}