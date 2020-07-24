package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 完全二叉树的节点个数
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution222 extends BaseBiTree {
    @Test
    public void test() {
        Assertions.assertEquals(6, countNodes(
                new TreeNode(1,
                        new TreeNode(2,
                                new TreeNode(4),
                                new TreeNode(5)),
                        new TreeNode(3,
                                new TreeNode(6),
                                null)))
        );
    }


    public int countNodes(TreeNode root) {
        // 当前二叉树的编号
        int count = 1;
        int leftLeaf = countLeft(root, count);
        int rightLeaf = countRight(root, count);
        // 表示非满二叉树
        while (leftLeaf > rightLeaf) {
            int midLeaf = countLeft(root.right, count * 2 + 1);

            if (leftLeaf < midLeaf) {
                // 左侧是满二叉树，在右侧找
                root = root.right;
                count = count * 2 + 1;
                leftLeaf = midLeaf;
            } else {
                // 左侧不是满二叉树，在左侧找
                root = root.left;
                count = count * 2;
                rightLeaf = countRight(root, count);
            }
        }
        return rightLeaf;
    }

    int countLeft(TreeNode root, int base) {
        if (root == null) {
            return 0;
        }
        while (root.left != null) {
            root = root.left;
            base = base * 2;
        }
        return base;
    }

    int countRight(TreeNode root, int base) {
        if (root == null) {
            return 0;
        }
        while (root.right != null) {
            root = root.right;
            base = base * 2 + 1;
        }
        return base;
    }
}
