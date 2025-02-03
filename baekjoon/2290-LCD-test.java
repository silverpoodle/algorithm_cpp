import java.util.*;
import java.io.*;

/*
지민이는 새로운 컴퓨터를 샀다. 하지만 새로운 컴퓨터에 사은품으로 온 LC-디스플레이 모니터가 잘 안나오는 것이다. 
지민이의 친한 친구인 지환이는 지민이의 새로운 모니터를 위해 테스트 할 수 있는 프로그램을 만들기로 하였다.

- 입력
    첫째 줄에 두 개의 정수 s와 n이 들어온다. (1 ≤ s ≤ 10, 0 ≤ n ≤ 9,999,999,999)이다. 
    n은 LCD 모니터에 나타내야 할 수 이며, s는 크기이다.

- 출력
    길이가 s인 '-'와 '|'를 이용해서 출력해야 한다. 
    각 숫자는 모두 s+2의 가로와 2s+3의 세로로 이루어 진다. 
    나머지는 공백으로 채워야 한다. 각 숫자의 사이에는 공백이 한 칸 있어야 한다.
*/

class Main {
    static boolean[][] num = {
            {true, true, true, false, true, true, true},     // 0
            {false, false, true, false, false, true, false}, // 1
            {true, false, true, true, true, false, true},    // 2
            {true, false, true, true, false, true, true},    // 3
            {false, true, true, true, false, true, false},   // 4
            {true, true, false, true, false, true, true},    // 5
            {true, true, false, true, true, true, true},     // 6
            {true, false, true, false, false, true, false},  // 7
            {true, true, true, true, true, true, true},      // 8
            {true, true, true, true, false, true, true}      // 9
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        String n = st.nextToken();
        
        StringBuilder[] sb = new StringBuilder[2*s + 3];
        for(int i = 0; i < 2*s + 3; i++) {
            sb[i] = new StringBuilder();
        }
        
        for(int i = 0; i < n.length(); i++) {
            int curr = n.charAt(i) - '0';
            
            sb[0].append(" ");
            if(num[curr][0]) {
                for(int j = 0; j < s; j++) sb[0].append("-");
            } else {
                for(int j = 0; j < s; j++) sb[0].append(" ");
            }
            sb[0].append(" ");
            
            for(int j = 1; j <= s; j++) {
                if(num[curr][1]) sb[j].append("|");
                else sb[j].append(" ");
                
                for(int k = 0; k < s; k++) sb[j].append(" ");
                
                if(num[curr][2]) sb[j].append("|");
                else sb[j].append(" ");
            }
            
            sb[s+1].append(" ");
            if(num[curr][3]) {
                for(int j = 0; j < s; j++) sb[s+1].append("-");
            } else {
                for(int j = 0; j < s; j++) sb[s+1].append(" ");
            }
            sb[s+1].append(" ");
            
            for(int j = s+2; j < 2*s+2; j++) {
                if(num[curr][4]) sb[j].append("|");
                else sb[j].append(" ");
                
                for(int k = 0; k < s; k++) sb[j].append(" ");
                
                if(num[curr][5]) sb[j].append("|");
                else sb[j].append(" ");
            }
            
            sb[2*s+2].append(" ");
            if(num[curr][6]) {
                for(int j = 0; j < s; j++) sb[2*s+2].append("-");
            } else {
                for(int j = 0; j < s; j++) sb[2*s+2].append(" ");
            }
            sb[2*s+2].append(" ");
            
            if(i < n.length()-1) {
                for(int j = 0; j < 2*s+3; j++) {
                    sb[j].append(" ");
                }
            }
        }
        
        for(int i = 0; i < 2*s+3; i++) {
            System.out.println(sb[i]);
        }
    }
}