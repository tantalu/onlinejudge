package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 交错字符串
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution97 {
    @Test
    public void test() {
        Assertions.assertTrue(isInterleave("aabcc", "dbbca", "aadbbcbcac"));
        Assertions.assertFalse(isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        boolean[] dp = new boolean[s2.length() + 1];
        dp[0] = true;
        // only s2
        for (int j = 1; j <= s2.length(); ++j) {
            int i2 = j - 1;
            dp[j] = dp[j - 1] && s3.charAt(i2) == s2.charAt(i2);
        }
        for (int i = 1; i <= s1.length(); ++i) {
            int i1 = i - 1;
            dp[0] = dp[0] && s3.charAt(i1) == s1.charAt(i1);
            for (int j = 1; j <= s2.length(); ++j) {
                int i2 = j - 1;
                int i3 = i + j - 1;
                dp[j] = (dp[j - 1] && s3.charAt(i3) == s2.charAt(i2)) || (dp[j] && s3.charAt(i3) == s1.charAt(i1));
            }
        }
        return dp[s2.length()];
    }
}
