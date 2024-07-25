#include <iostream>
#include <string>
using namespace std;

/* 6. 문자와 숫자가 섞여있는 문자열에서 자연수를 추출하고, 해당 자연수의 약수의 개수를 구하시오. (sdf00dsf2d8 -> 28 6) */

int main() {

    string input;
    string strNum = "";
    int cnt = 0;

    cin >> input;

    for(char c : input) {
        if (isdigit(c)) strNum += c;
    }

    int num = stoi(strNum);

    // for (int i = 1 ; i <= num ; i++) {
    //     if (num % i == 0) cnt++;
    // }

    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            cnt += (i * i == num) ? 1 : 2; 
        }
    }

    cout << num << " " << cnt << endl;

    return 0;
}