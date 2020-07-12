package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 乘积最大子数组
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution152 {
    @Test
    public void test() {
        Assertions.assertEquals(6, maxProduct(new int[]{2, 3, -2, 4}));
        Assertions.assertEquals(0, maxProduct(new int[]{-2, 0, -1}));
        Assertions.assertEquals(3, maxProduct(new int[]{-3, -1, -1}));
    }

    public int maxProduct(int[] nums) {
        return maxProduct(nums, 0, nums.length);
    }

    public int maxProduct(int[] nums, int start, int end) {
        if (end - start == 1) {
            return nums[start];
        }

        // 分治
        int mid = (start + end) / 2;
        int ans = Integer.MIN_VALUE;
        ans = Math.max(ans, maxProduct(nums, start, mid));
        ans = Math.max(ans, maxProduct(nums, mid, end));

        // 跨中点
        int leftPositive = 0;
        int leftNegative = 0;
        int product = 1;
        for (int i = mid - 1; i >= start; --i) {
            product *= nums[i];
            if (product > 0) {
                leftPositive = Math.max(leftPositive, product);
            } else if (product < 0) {
                leftNegative = Math.min(leftNegative, product);
            }
        }

        product = 1;
        int rightPositive = 0;
        int rightNegative = 0;
        for (int i = mid; i < end; ++i) {
            product *= nums[i];
            if (product > 0) {
                rightPositive = Math.max(rightPositive, product);
            } else if (product < 0) {
                rightNegative = Math.min(rightNegative, product);
            }
        }

        // == 0 代表没取到
        if (leftPositive > 0 && rightPositive > 0) {
            ans = Math.max(ans, leftPositive * rightPositive);
        }
        if (leftNegative < 0 && rightNegative < 0) {
            ans = Math.max(ans, leftNegative * rightNegative);
        }
        return ans;
    }
}
