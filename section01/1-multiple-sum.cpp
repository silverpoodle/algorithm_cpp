#include <iostream>
using namespace std;

/* 1. 자연수 N이 입력되면 1~N 중 M의 배수합을 출력하시오 (3<=M<N<=1000)*/

int main()
{
    int n, m, i, sum = 0;

    cin>>n>>m;

    for(i = 1 ; i <= n ; i++) {
        if(i % m == 0)
            sum += i;
    }
    cout<<sum<<endl;

    return 0;
}
