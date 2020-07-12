package tantalu.leetcode;

import org.junit.jupiter.api.Test;

/**
 * 插入区间
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution57 extends BaseMatrix {
    @Test
    public void test() {
        matrixEquals(new int[][]{{1, 5}, {6, 9}}, insert(new int[][]{{1, 3}, {6, 9}}, new int[]{2, 5}));
        matrixEquals(new int[][]{{1, 2}, {3, 10}, {12, 16}}, insert(new int[][]{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, new int[]{4, 8}));
        matrixEquals(new int[][]{{1, 2}, {4, 6}, {7, 9}}, insert(new int[][]{{1, 2}, {4, 6}, {7, 9}}, new int[]{4, 6}));
    }

    public int[][] insert(int[][] intervals, int[] newInterval) {
        int left = intervals.length, right = -1;
        for (int i = 0; i < intervals.length; i++) {
            if (intervals[i][1] >= newInterval[0]) {
                left = Math.min(left, i);
            }
            if (intervals[i][0] <= newInterval[1]) {
                right = Math.max(right, i);
            }
        }

        int[][] ans = new int[intervals.length - right + left][2];
        int index = 0;
        for (int i = 0; i < left; ++i) {
            ans[index++] = intervals[i];
        }
        if (right < 0 || left >= intervals.length) {
            ans[index++] = newInterval;
        } else {
            ans[index++] = new int[]{Math.min(intervals[left][0], newInterval[0]), Math.max(intervals[right][1], newInterval[1])};
        }
        for (int i = right + 1; i < intervals.length; ++i) {
            ans[index++] = intervals[i];
        }
        return ans;
    }
}
