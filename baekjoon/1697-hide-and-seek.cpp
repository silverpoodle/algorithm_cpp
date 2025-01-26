#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

/*
수빈이는 동생과 숨바꼭질을 하고 있다. 
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

- 입력
    첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

- 출력
    수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << 0;
        return 0;
    }

    queue<int> Q;
    int min_cnt[100010] = {0};

    Q.push(N);
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();

        if(node < 0 || node > 100000) continue;

        int moves[3] = {node - 1, node + 1, node * 2};

       for(int i : moves) {
            if(i >= 0 && i <= 100000 && min_cnt[i] == 0) {
                Q.push(i);
                min_cnt[i] = min_cnt[node] + 1;

                if(i == K) {
                    cout << min_cnt[i];
                    return 0;
                }
            }   
        }
    }
    return 0;
}