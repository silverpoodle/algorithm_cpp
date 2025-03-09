package leetcode;
import java.util.*;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        
        // int N = ransomNote.length();
        // int M = magazine.length();

        // if(M < N) return false;

        // HashMap<Character, Integer> counter = new HashMap<>();

        // for(Character c : magazine.toCharArray()) {
        //     counter.put(c, counter.getOrDefault(c, 0) + 1);
        // }

        // for(Character c : ransomNote.toCharArray()) {
        //     if(!counter.containsKey(c) || counter.get(c) <= 0) return false;
        //     counter.put(c, counter.get(c) - 1);
        // }

        // return true;

        int arr[] = new int[26];
        for(char a: magazine.toCharArray()){
            arr[a-'a']++;
        }
        for(char a: ransomNote.toCharArray()){
            if(arr[a-'a'] <= 0) return false;
            arr[a-'a']--;
        }
        return true;
    }
}