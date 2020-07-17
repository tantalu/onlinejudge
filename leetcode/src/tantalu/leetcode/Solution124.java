package tantalu.leetcode;

/**
 * @author jiafan
 * @version 1.0
 */
public class Solution124 extends BaseBiTree {
    public int maxPathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int[] sum = maxSum(root);
        return Math.max(Math.max(sum[0], sum[1]), sum[2]);
    }

    public int[] maxSum(TreeNode root) {
        if (root.left == null) {
            if (root.right == null) {
                return new int[]{Integer.MIN_VALUE, root.val, Integer.MIN_VALUE};
            } else {
                int[] rightSum = maxSum(root.right);
                return new int[]{
                        Math.max(rightSum[0], Math.max(rightSum[1], rightSum[2])),
                        Math.max(0, rightSum[1]) + root.val,
                        Integer.MIN_VALUE};
            }
        } else {
            if (root.right == null) {
                int[] leftSum = maxSum(root.left);
                return new int[]{
                        Math.max(leftSum[0], Math.max(leftSum[1], leftSum[2])),
                        Math.max(0, leftSum[1]) + root.val,
                        Integer.MIN_VALUE
                };
            } else {
                int[] leftSum = maxSum(root.left);
                int[] rightSum = maxSum(root.right);
                return new int[]{
                        Math.max(Math.max(leftSum[0], rightSum[0]), Math.max(Math.max(leftSum[1], rightSum[1]), Math.max(leftSum[2], rightSum[2]))),
                        Math.max(0, Math.max(leftSum[1], rightSum[1])) + root.val,
                        leftSum[1] + rightSum[1] + root.val
                };
            }
        }
    }
}
