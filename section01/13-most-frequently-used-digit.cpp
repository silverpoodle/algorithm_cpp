#include <iostream>
#include <time.h>

using namespace std;

/* 13. 자연수 N이 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자
       ex) 123333333 -> 3 
       (N 길이 <= 100)
       */


int main() {

    // int n;
    char a[101];
    int cnt[10] = {0};

    cin >> n;

    time_t start = time(NULL);

    // while (n > 0) {
    //     cnt[n % 10]++;
    //     n /= 10;
    // }

    // int max = 0;
    // int res = 0;

    // for(int i = 0 ; i < 10 ; i++) {
    //     if(cnt[i] >= max) {
    //         max = cnt[i];
    //         res = i;
    //     }
    // }
    // cout << res << endl;

    time_t end = time(NULL);

    
    cout << "time: " << (double)(end - start);

    return 0;
}