package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 通配符匹配
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution44 {
    @Test
    public void test() {
        Assertions.assertFalse(isMatch("aa", "a"));
        Assertions.assertTrue(isMatch("aa", "*"));
        Assertions.assertFalse(isMatch("cb", "*a"));
        Assertions.assertTrue(isMatch("adceb", "*a*b"));
        Assertions.assertFalse(isMatch("acdcb", "a*c?b"));
        Assertions.assertFalse(isMatch("aab", "c*a*b"));
    }

    public boolean isMatch(String s, String p) {
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= p.length(); ++i) {
            switch (p.charAt(i - 1)) {
                case '?':
                    System.arraycopy(dp, 0, dp, 1, s.length());
                    dp[0] = false;
                    break;
                case '*':
                    for (int j = 1; j <= s.length(); ++j) {
                        dp[j] = dp[j - 1] || dp[j];
                    }
                    break;
                default:
                    for (int j = s.length(); j > 0; --j) {
                        dp[j] = dp[j - 1] && s.charAt(j - 1) == p.charAt(i - 1);
                    }
                    dp[0] = false;
                    break;
            }
        }
        return dp[s.length()];
    }
}
