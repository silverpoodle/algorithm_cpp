// #include<iostream>

// using namespace std;

// /* 9. 자연수 N 이 입력되면 1~N 각 숫자의 약수의 개수를 모두 출력하시오. (5 <= N <= 50,000) */
// /* 시간 제한 1초 */

// int main() {

//     int n, cnt = 0;

//     cin >> n;

//     for(int i = 1 ; i <= n ; i++) {
//         for(int j = 1 ; j <= n ; j++) {
//             if (i%j == 0) cnt++;
//         }
//         cout << cnt << " ";
//         cnt = 0 ;
//     }
    
//     cout << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> countDivisors(int n) {

    vector<int> divisors(n+1, 1);

    for(int i = 2 ; i <= n; ++i) {
        for(int j = i ; j <= n ; j += i) {
            divisors[j]++;
        }
    }

    return divisors;
}

int main() {

    int n;
    cin >> n;

    vector<int> result = countDivisors(n);

     ofstream outFile("output.txt");
    if (!outFile) {
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        outFile << result[i] << " ";
    }
    outFile << endl;
    outFile.close();

    return 0;
}