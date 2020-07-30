package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 找到 K 个最接近的元素
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution658 extends BaseListNode {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new int[]{2, 3, 4, 5}, findClosestElements(new int[]{1, 2, 3, 4, 5}, 4, 4).stream().mapToInt(i -> i).toArray());
        Assertions.assertArrayEquals(new int[]{1, 2, 3, 4}, findClosestElements(new int[]{1, 2, 3, 4, 5}, 4, 3).stream().mapToInt(i -> i).toArray());
        Assertions.assertArrayEquals(new int[]{1, 2, 3, 4}, findClosestElements(new int[]{1, 2, 3, 4, 5}, 4, -1).stream().mapToInt(i -> i).toArray());
    }

    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        if (x <= arr[0]) {
            return newList(arr, 0, k);
        } else if (x >= arr[arr.length - 1]) {
            return newList(arr, arr.length - k, arr.length);
        }

        int index = Arrays.binarySearch(arr, x);
        if (index < 0) {
            index = arr[-1 - index] - x < x - arr[-2 - index] ? -1 - index : -2 - index;
        }
        int start = index - 1;
        int end = index + 1;
        for (int i = 1; i < k; ++i) {
            if (start < 0) {
                return newList(arr, 0, k);
            }
            if (end >= arr.length) {
                return newList(arr, arr.length - k, arr.length);
            }
            if (arr[end] - x < x - arr[start]) {
                ++end;
            } else {
                --start;
            }
        }
        return newList(arr, start + 1, end);
    }

    private List<Integer> newList(int arr[], int start, int end) {
        ArrayList<Integer> ans = new ArrayList<>(end - start);
        for (int i = start; i < end; ++i) {
            ans.add(arr[i]);
        }
        return ans;
    }
}
