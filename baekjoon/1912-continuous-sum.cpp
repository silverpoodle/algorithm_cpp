#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

/*
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 
단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 
여기서 정답은 12+21인 33이 정답이 된다.

- 입력
    첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 
    수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

- 출력
    첫째 줄에 답을 출력한다.
*/

// int main() {

//     int N;
//     cin >> N;

//     vector<int> arr(N);
//     for(int i = 0 ; i < N ; i++) cin >> arr[i];

//     vector<int> dp(N);

//     dp[0] = arr[0];
//     int max_sum = arr[0];

//     for(int i = 1 ; i < N ; i++) {
//         dp[i] = max(arr[i], dp[i - 1] + arr[i]);
//         max_sum = max(max_sum, dp[i]);
//     }

//     cout << max_sum;

//     return 0;
// }

// int main() {

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int N;
//     cin >> N;

//     int current_sum, max_sum;
//     cin >> current_sum;
//     max_sum = current_sum;

//     for(int i = 1 ; i < N ; ++i) {
//         int num;
//         cin >> num;

//         current_sum = max(num, current_sum + num);
//         max_sum = max(current_sum, max_sum);
//     }

//     cout << max_sum;

//     return 0;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N);
    int max_sum = dp[0];

    for(int i = 1 ; i <= N ; ++i) {
        int num;
        cin >> num;

        dp[i] = num + max(dp[i-1], 0);
        max_sum = max(max_sum, dp[i]);
    }

    cout << max_sum;

    return 0;
}