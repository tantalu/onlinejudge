package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

/**
 * 最接近的三数之和
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution16 {
    @Test
    public void test() {
        Assertions.assertEquals(-1, threeSumClosest(new int[]{-1, 2, 1, -4}, 0));
        Assertions.assertEquals(2, threeSumClosest(new int[]{-1, 2, 1, -4}, 1));
        Assertions.assertEquals(2, threeSumClosest(new int[]{1, 1, 1, 0}, -2));
        Assertions.assertEquals(82, threeSumClosest(new int[]{1, 2, 4, 8, 16, 32, 64, 128, 256}, 82));
        Assertions.assertEquals(16, threeSumClosest(new int[]{-111, -111, 3, 6, 7, 16, 17, 18, 19}, 13));
    }

    public int threeSumClosest(int[] nums, int target) {
        int upper = 100_000_000;
        int lower = -100_000_000;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    lower = Math.max(lower, sum);
                    for (int jj = j; j < k && nums[jj] == nums[j]; ++j) {
                    }
                } else {
                    upper = Math.min(upper, sum);
                    for (int kk = k; k > j && nums[kk] == nums[k]; --k) {
                    }
                }
            }
        }
        return upper - target < target - lower ? upper : lower;
    }
}
