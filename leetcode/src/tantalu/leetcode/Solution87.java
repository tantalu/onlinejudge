package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 扰乱字符串
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution87 {
    @Test
    public void test() {
        Assertions.assertTrue(isScramble("abc", "bca"));
        Assertions.assertTrue(isScramble("great", "rgeat"));
        Assertions.assertFalse(isScramble("abcde", "caebd"));
    }

    public boolean isScramble(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        int len = s1.length();
        boolean[][][] dp = new boolean[len + 1][len][len];
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                dp[1][i][j] = s1.charAt(i) == s2.charAt(j);
            }
        }
        for (int l = 2; l <= len; ++l) {
            for (int i = 0; i + l <= len; ++i) {
                for (int j = 0; j + l <= len; ++j) {
                    dp[l][i][j] = false;
                    for (int k = 1; k < l; ++k) {
                        if (dp[k][i][j] && dp[l - k][i + k][j + k] || dp[k][i][j + l - k] && dp[l - k][i + k][j]) {
                            dp[l][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[len][0][0];
    }
}
