import java.util.*;
import java.io.*;


/*
수빈이는 동생과 숨바꼭질을 하고 있다. 
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

- 입력
    첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

- 출력
    첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
    둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.
*/


class Main {

    static int N, K;
    static int[] parent = new int[100010];
    static int[] time = new int[100010];

    static void bfs() {
        Queue<Integer> Q = new LinkedList<>();
        Q.add(N);
        time[N] = 1;

        while(!Q.isEmpty()) {
            int node = Q.poll();

            if(node == K) return;
            
            int[] moves = {node + 1, node - 1, node * 2};
            for(int move : moves) {
               
                if(move < 0 || move == 100000) continue;
                if(time[move] == 0) {
                    Q.add(move);
                    time[move] = time[node] + 1;
                    parent[move] = node;
                }  
            }
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        bfs();
        
        Stack<Integer> S = new Stack<>();
        S.push(K);
        int index = K;

        while(index != N) {
            S.push(parent[index]);
            index = parent[index];
        }

        sb.append(time[K] - 1 + "\n");
        while(!S.isEmpty()) sb.append(S.pop() + " ");
        System.out.println(sb.toString());
    }
}