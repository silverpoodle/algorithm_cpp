#include <iostream>
#include <limits>
using namespace std;

/* 4. N(2<=N<=100)명의 나이가 입력되면 이 중 나이차이가 가장 많이 나는 경우는 몇 살인지 구하시오 */

int main()
{
    freopen("input.txt", "rt", stdin);
    // int n, i, a, min = 2147483647, max = 0;

    int n, a;
    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::min(); 

    cin >> n;

    for(int i = 0 ; i <= n ; i++) {
        cin >> a;

        if(a > max) max = a;
        if(a < min) min = a;
    }

    cout << max - min << endl;

    return 0;
}
