package leetcode;

import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> seen = new HashSet<>();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') continue; 

                if (!seen.add(num + " in row " + i)) return false;

                if (!seen.add(num + " in col " + j)) return false;

                int blockIndex = (i / 3) * 3 + j / 3;
                if (!seen.add(num + " in block " + blockIndex)) return false;
            }
        }
        return true;
    }
}
