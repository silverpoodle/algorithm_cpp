package section01;

import java.util.Scanner;
import java.util.*;
import java.io.*;

/*
 * N 이 입력되면 1 부터 N 까지의 소수의 개수 (제한시간 1초, 2 <= N <= 200,000)
 */

class Main {
    static int N;
    static boolean isPrime;
    static int cnt = 1;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        // for(int i = 2 ; i < N ; i++) {
        //     for(int j = 2 ; j < i ; j++) {
        //         isPrime = true;
        //         if(i%j == 0) {
        //             isPrime = false;
        //         }
        //     }
        //     if(isPrime) cnt++;
        // }
        // System.out.println(cnt);

        for(int i = 2 ; i <= N ; i++) {
            isPrime = true;
            for(int j = 2 ; j*j <= N ; j++) {
                if(i%j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) cnt++;
        }
        System.out.println(cnt);

    }
}