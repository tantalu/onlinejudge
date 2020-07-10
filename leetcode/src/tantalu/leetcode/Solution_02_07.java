package tantalu.leetcode;

/**
 * 链表相交
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution_02_07 extends BaseListNode {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }

        // 跳过不一样长的部分
        int lena = len(headA);
        int lenb = len(headB);
        int len;
        if (lena > lenb) {
            for (int i = 0; i < lena - lenb; ++i) {
                headA = headA.next;
            }
            len = lenb;
        } else if (lena < lenb) {
            for (int i = 0; i < lenb - lena; ++i) {
                headB = headB.next;
            }
            len = lena;
        } else {
            len = lena;
        }

        for (int i = 0; i < len; ++i) {
            if (headA == headB) {
                return headA;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }

    private int len(ListNode node) {
        int len = 0;
        for (; node != null; node = node.next) {
            ++len;
        }
        return len;
    }
}
