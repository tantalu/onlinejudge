package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 删除排序链表中的重复元素 II
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution82 extends BaseListNode {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new int[]{1, 2, 5}, toArray(deleteDuplicates(buildListNode(new int[]{1, 2, 3, 3, 4, 4, 5}))));
        Assertions.assertArrayEquals(new int[]{2, 3}, toArray(deleteDuplicates(buildListNode(new int[]{1, 1, 1, 2, 3}))));
    }

    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode first = new ListNode(0);
        first.next = head;
        for (ListNode node = first; node.next != null; ) {
            ListNode cur = node.next;
            ListNode p = cur.next;
            while (p != null && p.val == cur.val) {
                p = p.next;
            }
            if (p != cur.next) {
                node.next = p;
            } else {
                node = node.next;
            }
        }

        return first.next;
    }
}
