#include<iostream>
#include<vector>
using namespace std;

/*
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
단, 같은 수를 두 번 이상 연속해서 사용하면 안 된다.

1+2+1
1+3
3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

- 입력
    첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. 
    n은 양수이며 100,000보다 작거나 같다.

- 출력
    각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.
*/

int main() {

    int T;
    cin >> T;

    vector<int> cases(T + 1, 0);
    int maxNum = 0;

    for(int i = 1 ; i <= T ; i++) {
        cin >> cases[i];
        maxNum = max(maxNum, cases[i]);
    }

    vector<int> dp(maxNum + 1, 0);
    vector<vector<int>> dpCnt(maxNum + 1, vector<int>(4, 0));

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 3;

    dpCnt[1][1] = 1; 
    dpCnt[2][2] = 1; 
    dpCnt[3][1] = 1; dpCnt[3][2] = 1; dpCnt[3][3] = 1; 

    for (int i = 4 ; i <= maxNum ; i++) {
        for(int j = 1 ; j < 4 ; j++) {
            dp[i] += dp[i-j] - dpCnt[i-j][j];
            dpCnt[i][j] = dp[i-j] - dpCnt[i-j][j];
        }
    }

    for(int i = 1 ; i <= T ; i++) cout << dp[cases[i]] % 1000000009  << "\n";
}