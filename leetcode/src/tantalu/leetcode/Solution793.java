package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 阶乘函数后K个零
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution793 {
    @Test
    public void test() {
        Assertions.assertEquals(5, preimageSizeFZF(0));
        Assertions.assertEquals(0, preimageSizeFZF(5));
        Assertions.assertEquals(5, preimageSizeFZF(1000000000));
    }

    public int preimageSizeFZF(int K) {
        long lower = 4L * K;
        if (zeroCount(lower) == K) {
            return 5;
        }
        long upper = 5L * K;
        if (zeroCount(upper) == K) {
            return 5;
        }
        while (lower + 5 < upper) {
            long mid = (lower + upper) / 2;
            long count = zeroCount(mid);
            if (count == K) {
                return 5;
            } else if (count < K) {
                lower = mid;
            } else {
                upper = mid;
            }
        }
        return 0;
    }

    private long zeroCount(long num) {
        long ans = 0;
        while (num > 0) {
            num /= 5;
            ans += num;
        }
        return ans;
    }
}
