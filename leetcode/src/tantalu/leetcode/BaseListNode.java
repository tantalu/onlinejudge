package tantalu.leetcode;

import java.util.stream.IntStream;

/**
 * 链表
 *
 * @author jiafan
 * @version 1.0
 */
abstract class BaseListNode {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    ListNode buildListNode(int[] list) {
        ListNode head = new ListNode(0);
        ListNode tail = head;
        for (int i : list) {
            tail.next = new ListNode(i);
            tail = tail.next;
        }
        return head.next;
    }

    int[] toArray(ListNode node) {
        IntStream.Builder builder = IntStream.builder();
        while (node != null) {
            builder.accept(node.val);
            node = node.next;
        }
        return builder.build().toArray();
    }
}
