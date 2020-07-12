package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.List;

/**
 * 三角形最小路径和
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution120 {
    @Test
    public void test() {
        Assertions.assertEquals(11, minimumTotal(List.of(
                List.of(2),
                List.of(3, 4),
                List.of(6, 5, 7),
                List.of(4, 1, 8, 3)
        )));
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle.size() == 0) {
            return 0;
        }

        int[] mintotal = new int[triangle.size()];
        mintotal[0] = triangle.get(0).get(0);
        for (int i = 1; i < triangle.size(); ++i) {
            mintotal[i] = triangle.get(i).get(i) + mintotal[i - 1];
            for (int j = i - 1; j > 0; --j) {
                mintotal[j] = triangle.get(i).get(j) + Math.min(mintotal[j], mintotal[j - 1]);
            }
            mintotal[0] = triangle.get(i).get(0) + mintotal[0];
        }

        int ans = Integer.MAX_VALUE;
        for (int i : mintotal) {
            ans = Math.min(ans, i);
        }
        return ans;
    }
}
