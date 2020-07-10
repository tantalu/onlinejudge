package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 两两交换链表中的节点
 *
 * @author jiafan
 * @version 1.0
 */
public class Solotion24 extends BaseListNode {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new int[]{2, 1, 4, 3}, toArray(swapPairs(buildListNode(new int[]{1, 2, 3, 4}))));
        Assertions.assertArrayEquals(new int[]{2, 1, 4, 3, 5}, toArray(swapPairs(buildListNode(new int[]{1, 2, 3, 4, 5}))));
    }

    public ListNode swapPairs(ListNode head) {
        // 加个头结点
        ListNode headNode = new ListNode(0);
        headNode.next = head;

        ListNode node = headNode;
        while (true) {
            ListNode n = node.next;
            if (n == null) {
                break;
            }
            ListNode nn = n.next;
            if (nn == null) {
                break;
            }

            n.next = nn.next;
            nn.next = n;
            node.next = nn;

            node = n;
        }
        return headNode.next;
    }
}
