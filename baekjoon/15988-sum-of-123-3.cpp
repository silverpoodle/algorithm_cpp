#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

/*
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

- 입력
    첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. 
    n은 양수이며 1,000,000보다 작거나 같다.

- 출력
    각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.
*/

const ll MOD = 1000000009;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    vector<int> arr(T);
    int maxNum = 0;

    for(int i = 0 ; i < T ; i++) {
        cin >> arr[i];
        maxNum = max(arr[i], maxNum);
    }

    vector<int> dp(maxNum);

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;

    for(int i = 3 ; i < maxNum ; i++) {
        dp[i] = ((dp[i-1] + dp[i-2]) % MOD + dp[i-3]) % MOD;
    }

    for(int i = 0 ; i < T ; i++) cout << dp[arr[i]-1] << "\n";
}