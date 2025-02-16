import java.util.*;
import java.io.*;

/*
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

- 입력
    첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

- 출력
    한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/


class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        boolean[] isPrime = new boolean[N+1];
        
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        
        for(int i = 2; i <= Math.sqrt(N); i++) {
            if(isPrime[i]) {
                for(int j = i*i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = N ; i <= M ; i++) {
            if(isPrime[i]) sb.append(i).append("\n");
        }
        
        System.out.print(sb);
    }
}