package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

/**
 * 寻找两个正序数组的中位数
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution4 {
    @Test
    public void test() {
        Assertions.assertEquals(2.0, findMedianSortedArrays(new int[]{1, 3}, new int[]{2}));
        Assertions.assertEquals(2.5, findMedianSortedArrays(new int[]{1, 2}, new int[]{3, 4}));
        Assertions.assertEquals(2.0, findMedianSortedArrays(new int[]{1, 2, 3}, new int[]{1, 2, 2}));
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len = nums1.length + nums2.length;
        return len % 2 == 1 ? findMedianSortedArrays(nums1, nums2, len / 2)
                : (findMedianSortedArrays(nums1, nums2, len / 2) + findMedianSortedArrays(nums1, nums2, len / 2 - 1)) / 2;
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2, int top) {
        int from1 = 0;
        int to1 = nums1.length;
        int from2 = 0;
        int to2 = nums2.length;

        while (true) {
            if (from1 == to1) {
                return nums2[from2 + top];
            }
            if (from2 == to2) {
                return nums1[from1 + top];
            }

            int index1 = (from1 + to1) / 2;
            int cursor = nums1[index1];
            int index2 = Arrays.binarySearch(nums2, from2, to2, cursor);
            if (index2 < 0) {
                index2 = -1 - index2;
            }

            // 小于 cursor 的个数
            int sizeCursor = index1 - from1 + index2 - from2;
            if (sizeCursor == top) {
                return cursor;
            } else if (sizeCursor < top) {
                from1 = index1 + 1;
                from2 = index2;
                top -= sizeCursor + 1;
            } else {
                to1 = index1;
                to2 = index2;
            }
        }
    }
}
