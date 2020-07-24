package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * @author jiafan
 * @version 1.0
 */
public class Solution201 {
    @Test
    public void test() {
        Assertions.assertEquals(4, rangeBitwiseAnd(5, 7));
        Assertions.assertEquals(0, rangeBitwiseAnd(0, 1));
    }

    public int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n = n & (n - 1);
        }
        return m & n;
    }
}
