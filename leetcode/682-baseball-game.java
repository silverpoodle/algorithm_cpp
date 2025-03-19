package leetcode;
import java.util.*;

class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> s = new Stack<>();

        for(String op : operations) {
            if(op == "+") {
                int top = s.pop();
                int newTop = s.peek() + top;
                s.push(top);
                s.push(newTop);
            }
            else if(op == "C") {
                s.pop();
            }
            else if(op == "D") {
                int newTop = s.peek() * 2;
                s.push(newTop);
            }
            else { 
                s.push(Integer.parseInt(op));
            }
        }
        int sum = 0;
        while(!s.isEmpty()) {
            sum += s.pop();
        }
        return sum;
    }
}

// Time: O(n)
// Space: O(n)