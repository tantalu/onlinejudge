package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.List;

/**
 * 寻找峰值
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution162 {
    @Test
    public void test() {
        Assertions.assertEquals(2, findPeakElement(new int[]{1, 2, 3, 1}));
        Assertions.assertTrue(List.of(1, 5).contains(findPeakElement(new int[]{1, 2, 1, 3, 5, 6, 4})));
    }

    public int findPeakElement(int[] nums) {
        int start = 0, end = nums.length - 1;
        while (start < end) {
            // 分治
            int mid = (start + end) / 2;
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
}
