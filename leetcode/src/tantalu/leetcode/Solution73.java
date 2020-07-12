package tantalu.leetcode;

import org.junit.jupiter.api.Test;

/**
 * 矩阵置零
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution73 extends BaseMatrix {
    @Test
    public void test() {
        var matrix = new int[][]{
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1}
        };
        setZeroes(matrix);
        matrixEquals(new int[][]{
                {1, 0, 1},
                {0, 0, 0},
                {1, 0, 1}
        }, matrix);

        matrix = new int[][]{
                {0, 1, 2, 0},
                {3, 4, 5, 2},
                {1, 3, 1, 5}
        };
        setZeroes(matrix);
        matrixEquals(new int[][]{
                {0, 0, 0, 0},
                {0, 4, 5, 0},
                {0, 3, 1, 0}
        }, matrix);
    }

    public void setZeroes(int[][] matrix) {
        // 记录首行首列是否有0
        boolean firstRowZero = false;
        for (int i : matrix[0]) {
            firstRowZero |= i == 0;
        }
        boolean firstColZero = false;
        for (int[] row : matrix) {
            firstColZero |= row[0] == 0;
        }

        // 标记在首行首列上
        for (int i = 1; i < matrix.length; ++i) {
            for (int j = 1; j < matrix[0].length;
                 ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.length; ++i) {
            for (int j = 1; j < matrix[0].length; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < matrix[0].length; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < matrix.length; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
}
