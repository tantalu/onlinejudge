package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 反转链表 II
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution92 extends BaseListNode {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new int[]{1, 4, 3, 2, 5}, toArray(reverseBetween(buildListNode(new int[]{1, 2, 3, 4, 5}), 2, 4)));
        Assertions.assertArrayEquals(new int[]{3, 5}, toArray(reverseBetween(buildListNode(new int[]{5, 3}), 1, 2)));
    }

    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (n == m) {
            return head;
        }

        ListNode first = new ListNode(0);
        first.next = head;
        ListNode start = first;
        for (int i = 1; i < m; ++i) {
            start = start.next;
        }
        ListNode tail = start.next;
        for (int i = m; i < n; ++i) {
            ListNode recv = tail.next;
            tail.next = recv.next;
            recv.next = start.next;
            start.next = recv;
        }
        return first.next;
    }
}
