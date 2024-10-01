#include <iostream>

using namespace std;

/* 10. N개의 자연수가 입력되면 각 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력하라. (3 <= N <= 100)
       자리수의 합이 최대인 자연수가 여러개인 경우 그 중 값이 가장 큰 값을 출력*/

int digit_sum(int x) {
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int n, num = 0;
    int max_sum = -1, result = 0;

    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        int sum = digit_sum(num);

        if (sum > max_sum || (sum == max_sum && num > result)) {
            max_sum = sum;
            result = num;
        }
    }

    cout << result << endl;

    return 0;
}