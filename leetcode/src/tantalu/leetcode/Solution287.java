package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 寻找重复数
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution287 {
    @Test
    public void test() {
        Assertions.assertEquals(2, findDuplicate(new int[]{1, 3, 4, 2, 2}));
        Assertions.assertEquals(3, findDuplicate(new int[]{3, 1, 3, 4, 3}));
    }

    public int findDuplicate(int[] nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);
        return slow;
    }
}
