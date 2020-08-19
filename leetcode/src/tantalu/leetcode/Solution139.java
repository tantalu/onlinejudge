package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.List;

/**
 * @author jiafan
 * @version 1.0
 */
public class Solution139 {
    @Test
    public void test() {
//        Assertions.assertTrue(wordBreak("leetcode", List.of("leet", "code")));
//        Assertions.assertTrue(wordBreak("applepenapple", List.of("apple", "pen")));
//        Assertions.assertFalse(wordBreak("casandog", List.of("cats", "dog", "sand", "and", "cat")));
        Assertions.assertTrue(wordBreak("aaaaaaa", List.of("aaaa", "aa")));
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        return wordBreakBySearch(s, 0, wordDict);
    }

    public boolean wordBreakByDp(String s, List<String> wordDict) {
        int maxLength = 0;
        for (String dict : wordDict) {
            maxLength = Math.max(dict.length(), maxLength);
        }

        boolean[] ans = new boolean[s.length() + 1];
        ans[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = Math.max(0, i - maxLength); j < i; ++j) {
                if (ans[j] && wordDict.contains(s.substring(j, i))) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[s.length()];
    }

    public boolean wordBreakBySearch(String s, int start, List<String> wordDict) {
        if (start == s.length()) {
            return true;
        } else if (start > s.length()) {
            return false;
        }
        for (String word : wordDict) {
            if (isPrefix(s, start, word)) {
                if (wordBreakBySearch(s, start + word.length(), wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean isPrefix(String s, int start, String word) {
        for (int i = 0; i < word.length(); ++i) {
            if (start + i < s.length() && s.charAt(start + i) != word.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}
