package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 和为 K 的最少斐波那契数字数目
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution1414 {
    @Test
    public void test() {
        Assertions.assertEquals(2, findMinFibonacciNumbers(7));
        Assertions.assertEquals(3, findMinFibonacciNumbers(19));
        Assertions.assertEquals(1, findMinFibonacciNumbers(1));
    }

    public int findMinFibonacciNumbers(int k) {
        if (k == 0) {
            return 0;
        }

        int[] fibo = new int[50];
        fibo[0] = 1;
        fibo[1] = 1;
        int length = 2;
        while (true) {
            fibo[length] = fibo[length - 1] + fibo[length - 2];
            if (fibo[length] <= 0 || fibo[length] > k) {
                break;
            }
            ++length;
        }

        // 贪心
        int ans = 0;
        while (true) {
            --length;
            if (k == fibo[length]) {
                return ans + 1;
            } else if (k > fibo[length]) {
                k -= fibo[length];
                ans++;
            }
        }
    }
}
