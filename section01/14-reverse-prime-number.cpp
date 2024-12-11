#include <iostream>
#include <stack>
#include <time.h>

using namespace std;

/* 14. N개의 자연수가 입력되면 각 자연수를 뒤집은 후, 그 수가 소수 일 시 출력
       ex) 32 -> 23 (출력), 910 -> 19 (출력), 24 -> 42 (미출력)
       (3 <= N <= 100), 각 자연수 <= 100,000
       뒤집는 함수 int reverse(int x), 확인하는 함수 bool isPrime(int x) 반드시 사용 
*/

int reverse(int x) {
       int res = 0;
       int tmp;
       while (x > 0) {
              tmp = x % 10;
              res = res * 10 + tmp;
              x /= 10;
       }
       return res;
}

bool isPrime(int x) {
       
       if(x == 1) return false;

       bool flag = false;
       for (int i = 2 ; i < x ; i++) {
              if(x % i == 0) {
                     flag == false;
                     break;
              }
       }
       return flag;
}

int main() {

       freopen("input.txt", "rt", stdin);

       int n, num;

       scanf("%d", &n);

       for(int i = 0 ; i < n ; i++) {
              scanf("%d", &num);
              if (isPrime(reverse(num))) cout << num;
       }

}

