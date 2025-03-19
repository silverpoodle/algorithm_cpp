package leetcode;

import java.util.*;

// class Solution {
//     public int[] sortedSquares(int[] nums) {

//         int sqr[] = new int[nums.length];

//         for(int i = 0 ; i < nums.length ; i++) {
//             sqr[i] = nums[i] * nums[i];
//         }

//         Arrays.sort(sqr);

//         return sqr;
        
//     }
// } O(NlogN)

class Solution {
    public int[] sortedSquares(int[] nums) {

        int left = 0;
        int right = nums.length - 1;
        int i = nums.length - 1;

        int result[] = new int[nums.length];

        while(left <= right) {
            if(Math.abs(nums[left]) > Math.abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
                i--;
            }
            else {
                result[i] = nums[right] * nums[right];
                right--;
                i--;
            }
        }

        return result;
        
    }
} //O(N)