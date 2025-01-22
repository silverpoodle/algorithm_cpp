#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 


한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

- 입력
    첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

- 출력
    첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/

int N, M;
bool maze[110][110] = {false};
bool visited[110][110] = {false};
int cnt = 1;
int min_cnt = 10000;

int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;

    if(x == N && y == M) {
        min_cnt = min(min_cnt, cnt);
        return;
    }

    for(int i = 0 ; i < 4 ; i++) {
        int newX = x + dirX[i];
        int newY = y + dirY[i];
        if(maze[newX][newY] && !visited[newX][newY]) {
            cnt++;
            dfs(newX, newY);
            cnt--;
        }
    }
    visited[x][y] = false; 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1 ; i <= N ; i++) {
        string s;
        cin >> s;
        for (int j = 1 ; j <= M ; j++) {
            maze[i][j] = s.at(j-1) == '1';
        }
     }

    dfs(1, 1);
    cout << min_cnt;

    return 0;
}