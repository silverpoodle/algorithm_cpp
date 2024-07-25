#include <iostream>
#include <string>
using namespace std;

/* 5. 주민등록번호가 주어졌을 때(문자열) 나이와 성별을 출력하시오 */

int main()
{
    string num;
    char gender;
    int birthYear, currentYear = 2024;

    cin >> num;

    switch(num[7]) {
        case 1: case 3: gender = 'M'; birthYear == (num[7] == 1) ? 1900:2000; break;
        case 2: case 4: gender = 'W'; birthYear == (num[7] == 2) ? 1900:2000; break;
        default:
            cout << "잘못된 형식입니다." << endl;
            return 1;
    }

    birthYear += stoi(num.substr(0, 2)); //0, 1

    int age = currentYear - birthYear;

    cout << age << gender << endl;

    return 0;
}
