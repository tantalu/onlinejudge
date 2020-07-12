package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 长度最小的子数组
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution209 {
    @Test
    public void test() {
        Assertions.assertEquals(2, minSubArrayLen(7, new int[]{2, 3, 1, 2, 4, 3}));
        Assertions.assertEquals(1, minSubArrayLen(4, new int[]{1, 4, 4}));
    }

    public int minSubArrayLen(int s, int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int ans = 0;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end <= nums.length) {
            if (sum >= s) {
                if (ans == 0) {
                    ans = end - start;
                } else {
                    ans = Math.min(ans, end - start);
                }
                sum -= nums[start];
                ++start;
            } else {
                if (end == nums.length) {
                    break;
                }
                sum += nums[end];
                ++end;
            }
        }
        return ans;
    }
}
