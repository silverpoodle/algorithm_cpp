#include<iostream>
#include<vector>
using namespace std;

/*
수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가하는 부분 수열은 
A = {1* 100, 2*, 50*, 60*, 3, 5, 6, 7, 8} 이고, 합은 113이다.

- 입력
    첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
    둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

- 출력
    첫째 줄에 수열 A의 합이 가장 큰 증가하는 부분 수열의 합을 출력한다.
*/

int main() {

    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0 ; i < N ; i++) cin >> arr[i];

    vector<int> dp(N);
    int max_sum = 0;

    for(int i = 0 ; i < N ; i++) {
        dp[i] = arr[i];
        for(int j = 0 ; j < i ; j++) {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
        }
        max_sum = max(max_sum, dp[i]);
    }
    
    cout << max_sum;

}