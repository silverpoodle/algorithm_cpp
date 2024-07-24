#include <iostream>
using namespace std;

/* 3. 자연수 N이 입력되면 N의 진약수의 합을 수식과 함께 출력하시오 (3<N<=100)*/

int main()
{
    // int n, i, sum = 0; 
    int n, i, sum = 1; 

    cin >> n;

    cout << 1;

    for(i = 2 ; i < n ; i++) {
        if(n % i == 0){
            cout << '+' << i;
            sum += i;
        }
    }
    // cout<<'='<<sum+1<<endl;
    cout << '=' << sum << endl;

    return 0;
}
