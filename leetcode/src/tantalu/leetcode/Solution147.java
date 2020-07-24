package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 对链表进行插入排序
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution147 extends BaseListNode {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new int[]{1, 2, 3, 4, 5, 6, 7, 8}, toArray(insertionSortList(buildListNode(new int[]{6, 5, 3, 1, 8, 7, 2, 4}))));
        Assertions.assertArrayEquals(new int[]{1, 2, 3, 4}, toArray(insertionSortList(buildListNode(new int[]{4, 1, 2, 3}))));
        Assertions.assertArrayEquals(new int[]{-1, 0, 3, 4, 5}, toArray(insertionSortList(buildListNode(new int[]{-1, 5, 3, 4, 0}))));
    }

    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode first = new ListNode(0);
        first.next = head;
        for (ListNode tail = head; tail.next != null; ) {
            ListNode pre = first, cur = pre.next;
            while (pre != tail) {
                if (cur.val > tail.next.val) {
                    ListNode ins = tail.next;
                    pre.next = ins;
                    tail.next = ins.next;
                    ins.next = cur;
                    break;
                }
                pre = cur;
                cur = cur.next;
            }
            if (pre == tail) {
                tail = tail.next;
            }
        }
        return first.next;
    }
}
