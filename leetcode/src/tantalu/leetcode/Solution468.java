package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * 验证IP地址
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution468 {
    @Test
    public void test() {
        Assertions.assertEquals("IPv4", validIPAddress("172.16.254.1"));
        Assertions.assertEquals("Neither", validIPAddress("172.16.254.01"));
        Assertions.assertEquals("Neither", validIPAddress("256.256.256.256"));
        Assertions.assertEquals("IPv6", validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"));
        Assertions.assertEquals("IPv6", validIPAddress("2001:0db8:85a3:0000:0000:8a2e:0370:7334"));
        Assertions.assertEquals("Neither", validIPAddress("2001:0db8:85a3::8A2E:0370:7334"));
        Assertions.assertEquals("Neither", validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334"));
        Assertions.assertEquals("Neither", validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:"));
    }

    public String validIPAddress(String IP) {
        List<String> dotSplit = split(IP, '.');
        if (dotSplit.size() == 4) {
            for (String param : dotSplit) {
                char[] chars = param.toCharArray();
                switch (param.length()) {
                    case 1:
                        if (!Character.isDigit(chars[0])) {
                            return "Neither";
                        }
                        break;
                    case 2:
                        if (!(chars[0] >= '1' && chars[0] <= '9' && Character.isDigit(chars[1]))) {
                            return "Neither";
                        }
                        break;
                    case 3:
                        if (!(chars[0] == '1' && Character.isDigit(chars[1]) && Character.isDigit(chars[2])
                                || chars[0] == '2' && (chars[1] >= '0' && chars[1] <= '4' && Character.isDigit(chars[2])
                                || chars[1] == '5' && chars[2] >= '0' && chars[2] <= '5'))) {
                            return "Neither";
                        }
                        break;
                    default:
                        return "Neither";
                }
            }
            return "IPv4";
        }
        List<String> colonSplit = split(IP, ':');
        if (colonSplit.size() == 8) {
            for (String param : colonSplit) {
                if (param.length() <= 0 || param.length() > 4) {
                    return "Neither";
                }
                for (char c : param.toCharArray()) {
                    if (!(Character.isDigit(c) || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f')) {
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }
        return "Neither";
    }

    // String.split有问题
    // "12,3,".split(",") == ["12", "3"]
    // 自己写一个
    public List<String> split(String IP, char seperator) {
        List<String> ans = new ArrayList<>();
        int from = 0;
        do {
            int index = IP.indexOf(seperator, from);
            if (index == -1) {
                index = IP.length();
            }
            ans.add(IP.substring(from, index));
            from = index + 1;
        } while (from < IP.length());
        if (from == IP.length()) {
            ans.add("");
        }
        return ans;
    }
}
