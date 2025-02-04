import java.util.*;
import java.io.*;

/*
두 자연수 A와 B가 있을 때, A = BC를 만족하는 자연수 C를 A의 약수라고 한다. 
예를 들어, 2의 약수는 1, 2가 있고, 24의 약수는 1, 2, 3, 4, 6, 8, 12, 24가 있다. 
자연수 A의 약수의 합은 A의 모든 약수를 더한 값이고, f(A)로 표현한다. x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현한다.
자연수 N이 주어졌을 때, g(N)을 구해보자.

- 입력
    첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

- 출력
    첫째 줄에 g(N)를 출력한다.
*/

// g[10] = g[9] + f[10];

class Main {
    static long[] f;
    static long[] g;

    static void f(int N) {
        f = new long[N + 1];
        g = new long[N + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j += i) {
                f[j] += i;
            }
        }

        for (int i = 1; i <= N; i++) {
            g[i] = g[i - 1] + f[i];
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        f(N);

        System.out.println(g[N]);
    }
}

