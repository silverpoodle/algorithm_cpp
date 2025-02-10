import java.io.*;
import java.util.*;

class Main {
    static int N;
    static int[] numbers;
    static int[] operators = new int[4];  // +, -, *, /
    static int min = Integer.MAX_VALUE;
    static int max = Integer.MIN_VALUE;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        numbers = new int[N];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            operators[i] = Integer.parseInt(st.nextToken());
        }
        
        dfs(numbers[0], 1);
        
        System.out.println(max);
        System.out.println(min);
    }
    
    static void dfs(int result, int depth) {
        if (depth == N) {
            max = Math.max(max, result);
            min = Math.min(min, result);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            if (operators[i] > 0) {
                operators[i]--; 
                
                switch (i) {
                    case 0:
                        dfs(result + numbers[depth], depth + 1);
                        break;
                    case 1: 
                        dfs(result - numbers[depth], depth + 1);
                        break;
                    case 2:
                        dfs(result * numbers[depth], depth + 1);
                        break;
                    case 3:
                        dfs(result / numbers[depth], depth + 1);
                        break;
                }
                
                operators[i]++; 
            }
        }
    }
}