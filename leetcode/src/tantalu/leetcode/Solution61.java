package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 旋转链表
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution61 extends BaseListNode {
    @Test
    public void test() {
        Assertions.assertEquals(4, rotateRight(buildListNode(new int[]{1, 2, 3, 4, 5}), 2).val);
        Assertions.assertEquals(2, rotateRight(buildListNode(new int[]{0, 1, 2}), 4).val);
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return null;
        }

        // 长度
        int len = 0;
        ListNode tail = null;
        for (ListNode node = head; node != null; node = node.next) {
            tail = node;
            ++len;
        }

        int step = len - k % len;
        if (step == 0) {
            return head;
        }

        // 成环，右移变左移
        tail.next = head;
        ListNode newTail = head;
        for (int i = 1; i < step; ++i) {
            newTail = newTail.next;
        }
        ListNode newHead = newTail.next;
        newTail.next = null;
        return newHead;
    }
}