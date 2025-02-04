import java.util.*;
import java.io.*;

/*
2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.

- 입력
    입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.

- 출력
    각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.
*/

class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S;
        while((S = br.readLine()) != null) {
            int N = Integer.parseInt(S);
            int remainder = 1 % N;
            int cnt = 1;
            while (remainder != 0) {
                cnt++;
                remainder = (remainder * 10 + 1) % N;
            }
            System.out.println(cnt);
        }
    }
}
