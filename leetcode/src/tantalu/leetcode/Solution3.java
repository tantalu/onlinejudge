package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 无重复字符的最长子串
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution3 {
    @Test
    public void test() {
        Assertions.assertEquals(3, lengthOfLongestSubstring("abcabcbb"));
        Assertions.assertEquals(1, lengthOfLongestSubstring("bbbbb"));
        Assertions.assertEquals(3, lengthOfLongestSubstring("pwwkew"));
    }

    public int lengthOfLongestSubstring(String s) {
        int[] count = new int[128];
        int start = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (count[s.charAt(i)]++ == 0) {
                continue;
            }
            // 出现重复字母，清理到第一次出现的位置
            ans = Math.max(ans, i - start);
            for (int j = start; j < i; ++j) {
                count[s.charAt(j)] = 1;
                if (s.charAt(j) == s.charAt(i)) {
                    start = j + 1;
                    break;
                }
            }
        }
        // 包括末尾的情况
        return Math.max(ans, s.length() - start);
    }
}
