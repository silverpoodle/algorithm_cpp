#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

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

/* 틀린이유: overflow 고려할것....
1000000009*3 = int(21억) 넘음*/

const int MOD = 1000000009;

int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector<int> cases(T, 0);
    int maxNum = 0;

    for(int i = 0 ; i < T ; ++i) {
        cin >> cases[i];
        maxNum = max(maxNum, cases[i]);
    }

    vector<vector<int>> dp(maxNum + 1, vector<int>(4, 0));

    dp[1][1] = 1; 
    dp[2][2] = 1; 
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1; 

    for (int i = 4 ; i <= maxNum ; ++i) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }

    for (int i = 0; i < T; ++i) {
        int n = cases[i];
        ll result = ((ll)dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
        cout << result << "\n";
    }
}