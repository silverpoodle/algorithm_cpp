#include <iostream>
using namespace std;

/* 2. 자연수 A, B가 입력되면 A~B 합과 수식을 출력하시오 (1<=A<B<=100)*/

int main()
{
    int a, b, i, sum = 0;
    cin>>a>>b;

    for (i = a ; i <b ; i++) {
        cout<<i<<'+';
        sum += i;
    }
    // sum += b;
    cout<<b<<'='<<sum + i<<endl;

    return 0;
}
