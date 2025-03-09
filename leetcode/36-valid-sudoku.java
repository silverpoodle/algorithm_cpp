package leetcode;

import java.util.HashMap;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        HashMap<Integer, Integer> h = new HashMap<>();

        for(int i = 0 ; i < 9 ; i++) {
            h.put(i, 1);
        }

        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 9 ; j++) {
                if(h.get(board[i][j]) == 0) return false;
                h.put(board[i][j], h.get(board[i][j])-1);
            }
        }
    }
}