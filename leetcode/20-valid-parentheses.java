package leetcode;
import java.util.*;

// class Solution {
//     public boolean isMatch(Character a, Character b) {
//         switch (a) {
//             case '(':
//                 if(b == ')') return true;
//                 else return false;
        
//             case '{':
//                 if(b == '}') return true;
//                 else return false;

//             case '[':
//                 if(b == ']') return true;
//                 else return false;
//             default:
//                 return false;
//         }
//     }

//     public boolean isValid(String s) {
//         Stack<Character> stack = new Stack<>();

//         int N = s.length();
//         stack.push(s.charAt(0));
//         for(int i = 1 ; i < N ; i++) {
//             if(stack.isEmpty()) {
//                 stack.push(s.charAt(i));
//             }
//             else if(isMatch(stack.peek(), s.charAt(i))) {
//                 stack.pop();
//             }
//             else stack.push(s.charAt(i));
//         }
//         return stack.isEmpty();
//     } 
// }

class Solution {

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        HashMap<Character, Character> map = new HashMap<>();
        map.put(')', '(');
        map.put('}', '{');
        map.put(']', '[');

        for(char c : s.toCharArray()) {
            if(!map.containsKey(c)) stack.push(c);
            else {
                if(stack.isEmpty() || stack.pop() != map.get(c)) return false;
            }
        }
        return stack.isEmpty();
    } 
}
