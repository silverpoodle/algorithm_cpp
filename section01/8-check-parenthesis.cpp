#include<iostream>
#include<string>

using namespace std;

/* 8. 올바른 괄호쌍이 입력되었는지 확인하시오 (())))))(()))) */
int main() {

    string input, output="";

    cin >> input;

    for(char c : input) {
        if(c != ' ') {
            output += tolower(c);
        }
    }

    cout << output << endl;

    return 0;
}