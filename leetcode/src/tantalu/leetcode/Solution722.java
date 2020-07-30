package tantalu.leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * 删除注释
 *
 * @author jiafan
 * @version 1.0
 */
public class Solution722 {
    @Test
    public void test() {
        Assertions.assertArrayEquals(new String[]{
                        "int main()",
                        "{ ",
                        "  ",
                        "int a, b, c;",
                        "a = b + c;",
                        "}"},
                removeComments(new String[]{
                        "/*Test program */",
                        "int main()",
                        "{ ",
                        "  // variable declaration ",
                        "int a, b, c;",
                        "/* This is a test",
                        "   multiline  ",
                        "   comment for ",
                        "   testing */",
                        "a = b + c;",
                        "}"}).toArray());
        Assertions.assertArrayEquals(new String[]{"ab"},
                removeComments(new String[]{"a/*comment",
                        "line",
                        "more_comment*/b"}).toArray());
        Assertions.assertArrayEquals(new String[]{
                        "struct Node{",
                        "    ",
                        "    int size;",
                        "    int val;",
                        "};"},
                removeComments(new String[]{
                        "struct Node{",
                        "    /*/ declare members;/**/",
                        "    int size;",
                        "    /**/int val;",
                        "};"}).toArray());
        Assertions.assertArrayEquals(new String[]{
                        "a",
                        "blank",
                        "d/f"
                },
                removeComments(new String[]{
                        "a//*b//*c",
                        "blank",
                        "d/*/e*//f"
                }).toArray());
    }

    public List<String> removeComments(String[] source) {
        ArrayList<String> ans = new ArrayList<>(source.length);
        for (int i = 0; i < source.length; ++i) {
            String line = source[i];

            int lineStart = line.indexOf("//");
            int blockStart = line.indexOf("/*");
            while (blockStart != -1 || lineStart != -1) {
                // 行注释在前或者无块注释，处理行注释
                if (lineStart != -1 && (blockStart == -1 || lineStart < blockStart)) {
                    line = line.substring(0, lineStart);
                    break;
                }

                String before = line.substring(0, blockStart);
                // 找到块注释的末尾
                int blockEnd;
                for (blockEnd = line.indexOf("*/", Math.min(blockStart + 2, line.length()));
                     blockEnd == -1;
                     blockEnd = line.indexOf("*/")) {
                    ++i;
                    line = source[i];
                }

                // 要和前面剩下的拼起来
                line = before + line.substring(blockEnd + 2);
                // 后面可能还跟着注释，所以继续
                lineStart = line.indexOf("//");
                blockStart = line.indexOf("/*");
            }

            // 去掉空行
            if (!line.isEmpty()) {
                ans.add(line);
            }
        }
        return ans;
    }
}
