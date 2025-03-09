package leetcode;

import java.util.*;


class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        
        // int N = jewels.length();
        // int M = stones.length();
        // int cnt = 0;

        // for(int i = 0 ; i < N ; i++) {
        //     for(int j = 0 ; j < M ; j++) {
        //         if(jewels.charAt(i) == stones.charAt(j)) cnt++;
        //     }
        // }
        // O(N * M)


        // return cnt;

        HashSet<Character> set = new HashSet<>();
        int cnt = 0;

        for (char jewel : jewels.toCharArray()) {
            set.add(jewel);
        }

        for(char stone : stones.toCharArray()) {
            if (set.contains(stone)) cnt++;
        }
        
        return cnt;

    }
}