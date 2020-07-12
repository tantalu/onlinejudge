package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 颜色分类
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution75 {
    @Test
    public void test() {
        int[] nums = new int[]{2, 0, 2, 1, 1, 0};
        sortColors(nums);
        Assertions.assertArrayEquals(new int[]{0, 0, 1, 1, 2, 2}, nums);

        nums = new int[]{1, 2, 2, 2, 2, 0, 0, 0, 1, 1};
        sortColors(nums);
        Assertions.assertArrayEquals(new int[]{0, 0, 0, 1, 1, 1, 2, 2, 2, 2}, nums);

        nums = new int[]{0, 0};
        sortColors(nums);
        Assertions.assertArrayEquals(new int[]{0, 0}, nums);

        nums = new int[]{0, 2, 2, 2, 0, 2, 1, 1};
        sortColors(nums);
        Assertions.assertArrayEquals(new int[]{0, 0, 1, 1, 2, 2, 2, 2}, nums);
    }

    public void sortColors(int[] nums) {
        int index0 = 0;
        int index2 = nums.length - 1;
        int i = 0;
        int j = nums.length - 1;
        while (true) {
            while (i < nums.length && nums[i] <= 1) {
                if (nums[i] == 0) {
                    if (i != index0) {
                        nums[index0] = 0;
                        nums[i] = 1;
                    }
                    ++index0;
                }
                ++i;
            }
            while (j >= 0 && nums[j] >= 1) {
                if (nums[j] == 2) {
                    if (j != index2) {
                        nums[index2] = 2;
                        nums[j] = 1;
                    }
                    --index2;
                }
                --j;
            }
            if (i < j) {
                nums[i++] = 1;
                nums[index0++] = 0;
                nums[j--] = 1;
                nums[index2--] = 2;
            } else {
                break;
            }
        }
    }
}
