package leetcode;

import java.util.PriorityQueue;

class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b) -> b-a);

        for(int stone : stones) {
            maxHeap.offer(stone);
        }

        while (maxHeap.size() > 1) {
            int largest = maxHeap.poll();
            int secondLargest = maxHeap.poll();

            if(largest != secondLargest) {
                maxHeap.offer(largest - secondLargest);
            }
        }

        return maxHeap.isEmpty() ? 0 : maxHeap.peek();
    }
}
//Time: O(n log n)
//space: O(1);