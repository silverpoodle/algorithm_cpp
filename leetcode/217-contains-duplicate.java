package leetcode;
import java.util.*;

class Solution {
    public boolean containsDuplicate(int[] nums) {

        int N = nums.length;
        HashSet<Integer> set = new HashSet<>();

        // add O(1)
        // contains O(1)

        for(int i = 0 ; i < N ; i++) {
            if(set.contains(nums[i])) return true;
            set.add(nums[i]);
        }
        return false;
    }
}