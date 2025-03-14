import java.util.*;
import java.io.*;

/*
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.
1234567891011121314151617181920212223...
이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.

- 입력
    첫째 줄에 N(1 ≤ N ≤ 100,000,000)이 주어진다.

- 출력
    첫째 줄에 새로운 수의 자릿수를 출력한다.

*/

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        long ans = 0;
        int length = String.valueOf(N).length();

        for(int i = 1 ; i < length ; i++) {
            ans += i * (9 * Math.pow(10, i-1));
        }
        ans += length * (N - Math.pow(10, length -1) + 1);

        System.out.println(ans);
    }

}