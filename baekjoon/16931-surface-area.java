import java.util.*;
import java.io.*;

/*
크기가 N×M인 종이가 있고, 종이는 1×1크기의 칸으로 나누어져 있다. 
이 종이의 각 칸 위에 1×1×1 크기의 정육면체를 놓아 3차원 도형을 만들었다.

그림은 3×3 크기의 종이 위에 정육면체를 놓은 것이고, 겉넓이는 60이다.

- 입력
    첫째 줄에 종이의 크기 N, M이 주어진다.  1 ≤ N, M ≤ 100
    둘째 줄부터 N개의 줄에는 종이의 각 칸에 놓인 정육면체의 수가 주어진다. 1 ≤ 종이의 한 칸에 놓인 정육면체의 수 ≤ 100

- 출력
    첫째 줄에 도형의 겉넓이를 출력한다.
*/

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] cube = new int[N+2][M+2];
        
        for(int i = 0; i < N+2; i++) {
            Arrays.fill(cube[i], 0);
        }

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= M; j++) {
                cube[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int cnt = N * M * 2;

        for(int i = 0; i < N + 1; i++) {
            for(int j = 0; j < M + 1; j++) {
                cnt += Math.abs(cube[i][j] - cube[i+1][j]);
                cnt += Math.abs(cube[i][j] - cube[i][j+1]);
            }
        }

        System.out.println(cnt);
    }
}