package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

/**
 * 删除排序数组中的重复项 II
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution80 {
    @Test
    public void test() {
        int[] nums;
        nums = new int[]{1, 1, 1, 2, 2, 3};
        Assertions.assertEquals(5, removeDuplicates(nums));
        Assertions.assertArrayEquals(new int[]{1, 1, 2, 2, 3}, Arrays.copyOf(nums, 5));

        nums = new int[]{0, 0, 1, 1, 1, 1, 2, 3, 3};
        Assertions.assertEquals(7, removeDuplicates(nums));
        Assertions.assertArrayEquals(new int[]{0, 0, 1, 1, 2, 3, 3}, Arrays.copyOf(nums, 7));

        nums = new int[]{1, 1, 1, 1, 1, 1, 1, 1, 1};
        Assertions.assertEquals(2, removeDuplicates(nums));
        Assertions.assertArrayEquals(new int[]{1, 1}, Arrays.copyOf(nums, 2));
    }

    public int removeDuplicates(int[] nums) {
        if (nums.length <= 2) {
            return nums.length;
        }

        int ans = 1;
        int i = 1;
        while (i < nums.length) {
            if (ans != i) {
                nums[ans] = nums[i];
            }
            if (nums[i] == nums[ans - 1]) {
                // 有两个相同项，查找到下一个不同项
                while (i < nums.length && nums[i] == nums[ans]) {
                    ++i;
                }
            } else {
                ++i;
            }
            ++ans;
        }
        return ans;
    }
}
