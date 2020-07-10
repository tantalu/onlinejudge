package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 三数之和
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution15 {
    @Test
    public void test() {
        Assertions.assertEquals(2, threeSum(new int[]{-1, 0, 1, 2, -1, -4}).size());
        Assertions.assertEquals(1, threeSum(new int[]{0, 0, 0}).size());
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1, k = nums.length - 1; j < k; ++j) {
                int sum2 = nums[i] + nums[j];
                if (sum2 > 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                // 反向查找k
                while (j + 1 < k && sum2 + nums[k] > 0) {
                    --k;
                }
                if (sum2 + nums[k] == 0) {
                    ans.add(List.of(nums[i], nums[j], nums[k]));
                }
            }
        }
        return ans;
    }
}
