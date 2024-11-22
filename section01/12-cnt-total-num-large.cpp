#include <iostream>
#include <time.h>

using namespace std;

/* 12. 자연수 N이 입력되면 1 부터 N 까지 숫자가 몇 개 쓰였는가?
       예를 들어 11는 1,2,3,4,5,6,7,8,9,1,0,1,1 총 13개
       (3 <= N <= 1,000,000,000) 
       
       1~9 : 1 -> 9개
       10~99: 2 -> 90개
       100~999: 3 -> 900 개

       O(1) < O(log n) < O(n) < O(n log n) < O(N^2) < O(2^n) < O(n!) < O(n^n)
       */
        //N=1,000,000,000: time: 0


int main() {
    long n, cnt = 0, res = 0;
    int digitCnt = 1;
    int powerOfTen = 9;

    cin >> n;

    time_t start = time(NULL);

    while (cnt + powerOfTen < n) {  //15
        res += digitCnt * powerOfTen;
        cnt += powerOfTen;
        digitCnt++;
        powerOfTen *= 10;
    }

    res += ((n - cnt) * digitCnt);

    time_t end = time(NULL);

    cout << res << endl;
    cout << "time: " << (double)(end - start);

    return 0;
}