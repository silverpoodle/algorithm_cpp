package leetcode;

import java.util.*;
import java.math.*;

class Solution {
    public int maxNumberOfBalloons(String text) {

        // b a l l o o n = 1 1 2 2 1

        int counter[] = new int[26];

        for(Character c : text.toCharArray()) {
            counter[c-'a']++;
        }

        return Math.min(Math.min(Math.min(counter[1], counter[0]), Math.min(counter['l'-'a']/2, counter['o'-'a']/2)), counter['n'-'a']);
          
        
    }
}
