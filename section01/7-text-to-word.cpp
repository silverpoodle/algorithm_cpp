#include<iostream>
#include<string>

using namespace std;

/* 7. 대,소문자,공백이 섞이 문자열에서 단어를 추출하시오 (b e  A u Ti F     ul -> beautiful) */
int main() {

    string input, output="";

    getline(cin, input);

    for(char c : input) {
        if(c != ' ') {
            output += tolower(c);
        }
    }

    cout << output << endl;

    return 0;
}