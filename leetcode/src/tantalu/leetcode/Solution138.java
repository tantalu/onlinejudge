package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

/**
 * 复制带随机指针的链表
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution138 {
    @Test
    public void test() {
        Node copy = copyRandomListWithoutMap(buildNode(new Integer[][]{{1, 1}, {2, 1}}));
        Assertions.assertNotNull(copy);
    }

    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node copyHead = null;
        Map<Node, Node> map = new HashMap<>();
        for (Node node = head, pre = null; node != null; node = node.next) {
            // 复制
            Node copyNode = new Node(node.val);
            // 结构
            if (pre != null) {
                pre.next = copyNode;
            } else {
                copyHead = copyNode;
            }
            // 借地方存一下原始random`
            copyNode.random = node.random;

            map.put(node, copyNode);
            pre = copyNode;
        }

        for (Node node = copyHead; node != null; node = node.next) {
            // random
            node.random = map.get(node.random);
        }
        return copyHead;
    }

    public Node copyRandomListWithoutMap(Node head) {
        if (head == null) {
            return null;
        }

        // 在当前结点后面复制一个新的
        for (Node node = head; node != null; node = node.next.next) {
            Node copyNode = new Node(node.val);
            copyNode.next = node.next;
            copyNode.random = node.random;
            node.next = copyNode;
        }

        // 复制random
        Node copyHead = head.next;
        for (Node copyNode = copyHead; true; copyNode = copyNode.next.next) {
            if (copyNode.random != null) {
                copyNode.random = copyNode.random.next;
            }
            if (copyNode.next == null) {
                break;
            }
        }

        // 分裂
        for (Node node = head; node != null; node = node.next) {
            Node copyNode = node.next;
            node.next = copyNode.next;
            if (copyNode.next != null) {
                copyNode.next = copyNode.next.next;
            }
        }
        return copyHead;
    }

    private Node buildNode(Integer[][] input) {
        Node head = new Node(0);
        Node tail = head;
        for (Integer[] i : input) {
            tail.next = new Node(i[0]);
            tail = tail.next;
        }

        Node node = head;
        for (Integer[] i : input) {
            node = node.next;
            if (i[1] != null) {
                node.random = head.next.get(i[1]);
            }
        }
        return head.next;
    }

    class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }

        Node get(int index) {
            Node node = this;
            while (index-- > 0) {
                node = node.next;
            }
            return node;
        }
    }
}
