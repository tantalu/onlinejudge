package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * 矩形面积
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution233 {
    @Test
    public void test() {
        Assertions.assertEquals(2,
                computeArea(
                        -1500000001, 0,
                        -1500000000, 1,
                        1500000000, 0,
                        1500000001, 1
                ));
    }

    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // 两个矩形面积减去重合部分的面积，花式防溢出。。。
        return (int) ((((long) C) - A) * (((long) D) - B)
                + (((long) G) - E) * (((long) H) - F)
                - Math.max(0, (long) (Math.min(C, G)) - Math.max(A, E))
                * Math.max(0, (long) (Math.min(D, H)) - Math.max(B, F)));
    }
}
