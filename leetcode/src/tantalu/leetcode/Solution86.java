package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 分隔链表
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution86 extends BaseListNode {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new int[]{1, 2, 2, 4, 3, 5}, toArray(partition(buildListNode(new int[]{1, 4, 3, 2, 5, 2}), 3)));
    }

    public ListNode partition(ListNode head, int x) {
        if (head == null) {
            return null;
        }

        ListNode lessStart = null, lessEnd = null, moreStart = null, moreEnd = null;
        for (ListNode p = head; p != null; p = p.next) {
            if (p.val < x) {
                if (lessEnd == null) {
                    lessEnd = lessStart = p;
                } else {
                    lessEnd.next = p;
                    lessEnd = lessEnd.next;
                }
            } else {
                if (moreEnd == null) {
                    moreEnd = moreStart = p;
                } else {
                    moreEnd.next = p;
                    moreEnd = moreEnd.next;
                }
            }
        }
        if (lessEnd == null) {
            return moreStart;
        } else {
            lessEnd.next = moreStart;
            if (moreEnd != null) {
                moreEnd.next = null;
            }
            return lessStart;
        }
    }
}
