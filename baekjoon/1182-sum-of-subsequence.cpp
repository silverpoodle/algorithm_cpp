#include <iostream>
#include <vector>
using namespace std;

/*
N개의 정수로 이루어진 수열이 있을 때, 
크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 
경우의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. 
(1 ≤ N ≤ 20, |S| ≤ 1,000,000) 

둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 
주어지는 정수의 절댓값은 100,000을 넘지 않는다.
*/


main() {

    int N, S;
    int cnt = 0;  
    int arr[20];

    cin >> N >> S;

    for (int i = 0; i < N ; i++) cin >> arr[i];

    for (int i = 0 ; i < (i << N) ; i++) {
        int sum = 0;

        for (int j = 0; j < N ; j++) {
            if (i & (i << j)) {
                sum += arr[j];
            }
        }

        if (sum == S) cnt++;
    }

    cout << cnt;

    return 0;

}