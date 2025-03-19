package leetcode;
import java.util.*;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();

        for(String token : tokens) {
            int second;
            int first;
            
            switch (token) {
                case "+":
                    second = stack.pop();
                    first = stack.pop();
                    stack.push(first + second);
                    break;
                case "-":
                    second = stack.pop();
                    first = stack.pop();
                    stack.push(first - second);
                    break;
                case "*":
                    second = stack.pop();
                    first = stack.pop();
                    stack.push(first * second);
                    break;
                case "/":
                    second = stack.pop();
                    first = stack.pop();
                    stack.push(Math.round(first/second));
                    break;
                default:
                    stack.push(Integer.parseInt(token));
                    break;
            }
        }
        return stack.pop();
    }
}
