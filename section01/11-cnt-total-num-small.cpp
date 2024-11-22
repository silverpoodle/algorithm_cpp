#include <iostream>

using namespace std;

/* 11. 자연수 N이 입력되면 1 부터 N 까지 숫자가 몇 개 쓰였는가?
       예를 들어 11는 1,2,3,4,5,6,7,8,9,1,0,1,1 총 13개
       (3 <= N <= 100,000) */

       //N=1,000,000,000: time: 2

int main() {
    int n, cnt = 0;

    cin >> n;

    for(int i = 1 ; i <= n ; i++) {
        cnt += i/10 + 1;
    }

    cout << cnt << endl;

    return 0;
}