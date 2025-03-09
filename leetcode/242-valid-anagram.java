package leetcode;

class Solution {
    public boolean isAnagram(String s, String t) {

        int S = s.length();
        int T = t.length();

        if(S != T) return false;

        int dict[] = new int[26];

        for(int i = 0 ; i < S ; i++) {
            dict[s.charAt(i) - 'a']++;
        }

        for(int i = 0 ; i < T ; i++) {
            if(dict[t.charAt(i) - 'a'] == 0) return false;
            dict[t.charAt(i) - 'a']--;
        }

        return true;
        
    }
}