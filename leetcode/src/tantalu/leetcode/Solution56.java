package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author jiafan
 * @version 1.0
 */
public class Solution56 extends BaseMatrix {
    @Test
    public void test() {
        matrixEquals(new int[][]{{1, 6}, {8, 10}, {15, 18}}, merge(new int[][]{{1, 3}, {2, 6}, {8, 10}, {15, 18}}));
        matrixEquals(new int[][]{{1, 5}}, merge(new int[][]{{1, 4}, {4, 5}}));
        matrixEquals(new int[][]{{1, 15}}, merge(new int[][]{{1, 15}, {6, 8}, {4, 5}}));
        matrixEquals(new int[][]{{1, 10}}, merge(new int[][]{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}}));
        matrixEquals(new int[][]{{}}, merge(new int[][]{{}}));
    }

    void matrixEquals(int[][] expected, int[][] actural) {
        Assertions.assertEquals(expected.length, actural.length);
        for (int i = 0; i < expected.length; ++i) {
            Assertions.assertArrayEquals(expected[i], actural[i]);
        }
    }

    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) {
            return intervals;
        }
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int index = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= intervals[index][1]) {
                intervals[index][1] = Math.max(intervals[index][1], intervals[i][1]);
            } else {
                intervals[++index] = intervals[i];
            }
        }
        return Arrays.copyOf(intervals, index + 1);
    }
}
