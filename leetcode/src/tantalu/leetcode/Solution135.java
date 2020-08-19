package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 分发糖果
 *
 * @author jiafan
 * @version 1.0
 */
class Solution135 {
    @Test
    public void test() {
        Assertions.assertEquals(7, candy(new int[]{1, 3, 2, 2, 1}));
    }

    public int candy(int[] ratings) {
        if (ratings.length == 0) {
            return 0;
        }

        /*
          上升、水平、下降三段分别求和
          上升：1, 2, 3, ...
          水平：1, 1, 1, ...
          下降：...,  3, 2, 1
         */
        int ans = 1;
        int sublength = 1;  // 单调段长度
        int firstValue = 0; // 下降段起始值
        int sign = 1;       // 当前上升下降趋势
        for (int i = 1; i < ratings.length; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                if (sign < 0) {
                    ans += sumDown(sublength, firstValue);
                    sublength = 2;
                } else if (sign == 0) {
                    ans += sumFlat(sublength);
                    sublength = 2;
                } else {
                    ++sublength;
                }
                sign = 1;
            } else if (ratings[i - 1] > ratings[i]) {
                if (sign < 0) {
                    ++sublength;
                } else if (sign == 0) {
                    ans += sumFlat(sublength);
                    firstValue = 1;
                    sublength = 2;
                } else {
                    ans += sumUp(sublength);
                    firstValue = sublength;
                    sublength = 2;
                }
                sign = -1;
            } else {
                if (sign < 0) {
                    ans += sumDown(sublength, firstValue);
                    sublength = 2;
                } else if (sign == 0) {
                    ++sublength;
                } else {
                    ans += sumUp(sublength);
                    sublength = 2;
                }
                sign = 0;
            }
        }

        if (sign < 0) {
            ans += sumDown(sublength, firstValue);
        } else if (sign == 0) {
            ans += sumFlat(sublength);
        } else {
            ans += sumUp(sublength);
        }
        return ans;
    }

    /**
     * 上升段的和
     *
     * @param length 上升段长度
     * @return 不包含第一个元素
     */
    int sumUp(int length) {
        return (length - 1) * (length + 2) / 2;
    }

    /**
     * 水平段的和
     *
     * @param length 水平段长度
     * @return 不包含第一个元素
     */
    int sumFlat(int length) {
        return length - 1;
    }

    /**
     * 下降段的和
     *
     * @param length 下降段长度
     * @param pre    第一个元素的初始值
     * @return 包含第一个元素和最后一个
     */
    int sumDown(int length, int pre) {
        return length * (length - 1) / 2 + Math.max(length - pre, 0);
    }
}
