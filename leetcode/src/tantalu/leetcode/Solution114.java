package tantalu.leetcode;

/**
 * 二叉树展开为链表
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution114 extends BaseBiTree {
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }

        for (TreeNode p = root; p != null; p = p.right) {
            if (p.left == null) {
                continue;
            }

            TreeNode left = p.left;
            while (left.right != null) {
                left = left.right;
            }
            left.right = p.right;
            p.right = p.left;
            p.left = null;
        }
    }
}
