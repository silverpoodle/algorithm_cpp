#include<iostream>
#include<vector>
using namespace std;

/*
45656이란 수를 보자.
이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

- 입력
    첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

- 출력
    첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
*/

const int MOD = 1000000000;

int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> dp(N ,vector<int>(10,0));

    for(int i = 1 ; i < 10 ; ++i) {
       dp[0][i] = 1;
    }

    for(int i = 1 ; i < N ; ++i) {
        for(int j = 0 ; j < 10 ; ++j) {
            if(j > 0) dp[i][j] += dp[i - 1][j - 1];
            if(j < 9) dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
    }

    long long sum = 0;
    for(int i = 0 ; i < 10 ; ++i) {
        sum += dp[N-1][i];
        sum %= MOD;
    }

    cout << sum;

    return 0;
}