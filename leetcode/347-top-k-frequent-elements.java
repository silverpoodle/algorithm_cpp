package leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for(int num : nums) {
            count.put(num, count.getOrDefault(num,0) + 1);
        }

        PriorityQueue<Map.Entry<Integer,Integer>> heap = new PriorityQueue<>(
            (a,b) -> (b.getValue() - a.getValue())
        );

        for(Map.Entry<Integer,Integer> entry : count.entrySet()) {
            if(heap.size() < k) heap.offer(entry);
            else {
                heap.offer(entry);
                heap.poll();
            }
        }

        int[] topK = new int[k];
        for(int i = k-1 ; i >= 0 ; i--) {
            topK[i] = heap.poll().getKey();
        }

        return topK;
    } 
}