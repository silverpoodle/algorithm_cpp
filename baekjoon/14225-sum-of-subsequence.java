import java.util.*;
import java.io.*;

/*
수열 S가 주어졌을 때, 수열 S의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 구하는 프로그램을 작성하시오.

예를 들어, S = [5, 1, 2]인 경우에 1, 2, 3(=1+2), 5, 6(=1+5), 7(=2+5), 8(=1+2+5)을 만들 수 있다. 
하지만, 4는 만들 수 없기 때문에 정답은 4이다.

- 입력
    첫째 줄에 수열 S의 크기 N이 주어진다. (1 ≤ N ≤ 20)
    둘째 줄에는 수열 S가 주어진다. S를 이루고있는 수는 100,000보다 작거나 같은 자연수이다.

- 출력
    첫째 줄에 수열 S의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 출력한다.
*/

class Main {

    static int N;
    static int[] S;
    static boolean[] visited;
    static int maxSum = 0;

    static void generateSums(int index, int currentSum) {
        if (index == N) {
            if (currentSum > 0) {
                visited[currentSum] = true;
            }
            return;
        }
        generateSums(index + 1, currentSum + S[index]);
        generateSums(index + 1, currentSum);
    }

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        S = new int[N];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            S[i] = Integer.parseInt(st.nextToken());
            maxSum += S[i];
        }
        
        visited = new boolean[maxSum + 2];
        
        generateSums(0, 0);
        
        int answer = 1;
        while (answer <= maxSum) {
            if (!visited[answer]) {
                break;
            }
            answer++;
        }
        
        System.out.println(answer);
    }
}