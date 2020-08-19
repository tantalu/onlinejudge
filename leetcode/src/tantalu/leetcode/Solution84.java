package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 柱状图中最大的矩形
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution84 {
    @Test
    public void test() {
        Assertions.assertEquals(10, largestRectangleArea(new int[]{2, 1, 5, 6, 2, 3}));
        Assertions.assertEquals(12, largestRectangleArea(new int[]{2, 1, 5, 6, 4, 3}));
    }

    public int largestRectangleArea(int[] heights) {
        int ans = 0;
        Deque<Integer> x = new LinkedList<>();
        Deque<Integer> y = new LinkedList<>();

        for (int i = 0; i < heights.length; ++i) {
            int cur = heights[i];
            int lastx = i;
            while (!y.isEmpty() && y.peek() > cur) {
                ans = Math.max(ans, (i - x.peek()) * y.peek());
                lastx = x.pop();
                y.pop();
            }
            if (!y.isEmpty() && y.peek() == cur) {
                continue;
            }
            x.push(lastx);
            y.push(cur);
        }
        while (!x.isEmpty()) {
            ans = Math.max(ans, (heights.length - x.peek()) * y.peek());
            x.pop();
            y.pop();
        }
        return ans;
    }
}
