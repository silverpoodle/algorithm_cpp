#include<iostream>
#include<string>
#include<stack>

using namespace std;

/* 8. 올바른 괄호쌍이 입력되었는지 확인하시오 (())))))(()))) */
int main() {

    string input, output="";
    stack<char> s;

    cin >> input;

    for(char c : input) {
        if(c == '(') {
            s.push(c);
        } else if (c == ')') {
            if(s.empty()) {
                cout << "NO" << endl;
                return 0;
            }
             else 
                s.pop();
        }
    }

    if(s.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}