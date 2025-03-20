package leetcode;

import java.util.PriorityQueue;

// class Solution {
//     public int findKthLargest(int[] nums, int k) {
//         PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b) -> b-a);

//         for(int num : nums) {
//             maxHeap.offer(num);
//         }

//         for(int i = 0 ; i < k-1 ; i++) {
//             maxHeap.poll();
//         }

//         return maxHeap.peek();
//     }
// }

//time: (n + k log n)

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for(int num : nums) {
            if(minHeap.size() < k) minHeap.offer(num);
            else {
                if(num > minHeap.peek()) {
                    minHeap.poll();
                    minHeap.offer(num);
                }
            }
        }
        return minHeap.peek();
    }
}

//time: n log k