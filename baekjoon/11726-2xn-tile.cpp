#include<iostream>
#include<vector>
using namespace std;

/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

- 입력
    첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

- 출력
    첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

/* 현섭 풀이: 1과 2의 조합 */

int main() {
    int N;
    cin >> N;

    vector<int> dp(N);

    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2 ; i < N ; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[N-1];
   
}