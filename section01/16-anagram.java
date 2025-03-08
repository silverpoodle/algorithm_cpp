package section01;

import java.util.*;
import java.io.*;

/*
 * 두 문자열의 알파벳이 나열순서는 나르지만 구성이 일치하면 Anagram.
 * Ex. AbaAeCe, baeeACA -> 알파벳과 개수 모두 일치
 * 두 개의 단어가 주어지면 두 단어가 Anagram 인지 아닌지 판별 (단어의 길이는 100을 넘지 않음)
 */

class Main {

    static String str1;
    static String str2;
    static boolean used[];

    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);

    //     str1 = sc.nextLine();
    //     str2 = sc.nextLine();

    //     int N = str1.length();

    //     if(N != str2.length()) {
    //         System.out.println("NO");
    //         return;
    //     }

    //     used = new boolean[N];
    //     boolean found;

    //     for(int i = 0; i < N ;i++) {
    //         found = false;
    //         for(int j = 0 ; j < N ; j++) {
    //             if(str2.charAt(j) == str1.charAt(i) && !used[j]) {
    //                 used[j] = true;
    //                 found = true;
    //                 break;
    //             }
    //         }
    //         if(!found) {
    //             System.out.println("NO");
    //             return;
    //         }
    //     }

    //     System.out.println("YES");
    //     return;
    // }

    //HashMap O(N)
    // public static void main(String[] args) {

    //     Scanner sc = new Scanner(System.in);

    //     str1 = sc.nextLine();
    //     str2 = sc.nextLine();

    //     int N = str1.length();

    //     if(N != str2.length()) {
    //         System.out.println("NO");
    //         return;
    //     }
    //     HashMap<Character, Integer> charCnt = new HashMap<>();

    //     for(int i = 0 ; i < N ; i++) 
    //         charCnt.put(str1.charAt(i), charCnt.getOrDefault(i,0)+1);
        
    //     for(int i = 0 ; i < N ; i++) {
    //         if(!charCnt.containsKey(str2.charAt(i)) || charCnt.get(str2.charAt(i)) == 0) {
    //             System.out.println("NO");
    //             return;
    //         }
    //         charCnt.put(str2.charAt(i), charCnt.get(str2.charAt(i))-1);
    //     }

    //     System.out.println("YES");
    //     return;
    // }



    //Alphabet 배열
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        str1 = sc.nextLine();
        str2 = sc.nextLine();

        int N = str1.length();

        if(N != str2.length()) {
            System.out.println("NO");
            return;
        }

        int[] count = new int[52];

        for(int i = 0 ; i < N ; i++) count[str1.charAt(i) - 'a']++;

        for(int i = 0 ; i < N ; i++) {
            count[str2.charAt(i) - 'a']--;
            if(count[str2.charAt(i) - 'a'] < 0) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
        return;
    }

}