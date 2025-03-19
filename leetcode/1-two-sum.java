package leetcode;

import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {

        int N = nums.length;

        HashMap<Integer, Integer> h = new HashMap<>();

        for(int i = 0 ; i < N ; i++) {
            int complement = target - nums[i];
            if(h.containsKey(complement)) {
                return new int[]{h.get(complement), i};
            }
            h.put(nums[i], i);
        }

        return new int[]{};
    }
}