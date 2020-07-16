package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * 复原IP地址
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution93 {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new String[]{"255.255.11.135", "255.255.111.35"}, restoreIpAddresses("25525511135").toArray(new String[0]));
        Assertions.assertArrayEquals(new String[]{"1.2.3.0"}, restoreIpAddresses("1230").toArray(new String[0]));
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        parseIp(ans, s.toCharArray(), 0, new ArrayList<>(4));
        return ans;
    }

    void parseIp(List<String> ans, char[] chars, int start, List<String> ip) {
        int left = chars.length - start;
        if (ip.size() == 4) {
            if (left == 0) {
                ans.add(ip.get(0) + '.' + ip.get(1) + '.' + ip.get(2) + '.' + ip.get(3));
                return;
            }
            return;
        }
        if (left == 0) {
            return;
        }

        // 1位
        ip.add(new String(chars, start, 1));
        parseIp(ans, chars, start + 1, ip);
        ip.remove(ip.size() - 1);

        // 2位
        if (left >= 2 && chars[start] != '0') {
            ip.add(new String(chars, start, 2));
            parseIp(ans, chars, start + 2, ip);
            ip.remove(ip.size() - 1);
        }

        // 3位
        if (left >= 3 && (chars[start] == '1'
                || chars[start] == '2' && (chars[start + 1] >= '0' && chars[start + 1] <= '4'
                || chars[start + 1] == '5' && chars[start + 2] >= '0' && chars[start + 2] <= '5'))) {
            ip.add(new String(chars, start, 3));
            parseIp(ans, chars, start + 3, ip);
            ip.remove(ip.size() - 1);
        }
    }
}
