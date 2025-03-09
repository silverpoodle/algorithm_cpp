package leetcode;

import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {

        int N = nums.length;
        int ans[] = new int[2];

        HashMap<Integer, Integer> counter = new HashMap<>();

        for(int i = 0 ; i < N ; i++) {
            counter.put(i, target-nums[i]);
        }

        for(int i = 0 ; i < N ; i++) {
            if(counter.containsValue(nums[i])) {
                ans[0] = i;
                ans[1] = counter.get(i);
                break;
            }
        }
        return ans;
    }
}