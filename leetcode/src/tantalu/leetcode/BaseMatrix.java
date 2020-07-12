package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;

/**
 * @author jiafan
 * @version 1.0
 */
abstract class BaseMatrix {

    void matrixEquals(int[][] expected, int[][] actural) {
        Assertions.assertEquals(expected.length, actural.length);
        for (int i = 0; i < expected.length; ++i) {
            Assertions.assertArrayEquals(expected[i], actural[i]);
        }
    }
}
