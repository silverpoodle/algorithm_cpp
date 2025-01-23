#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

/*
체스판 위에 한 나이트가 놓여져 있다. 
나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 
나이트가 이동하려고 하는 칸이 주어진다. 
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

- 입력
    입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
    각 테스트 케이스는 세 줄로 이루어져 있다. 
    첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 
    체스판의 크기는 l × l이다. 
    체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 
    둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

- 출력
    각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.
*/
int dirX[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dirY[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int dist[300][300];
bool visited[300][300];

int L;

int bfs(int startX, int startY, int endX, int endY) {
    memset(dist, 0, sizeof(dist));
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> Q;
    Q.push({startX, startY});
    visited[startX][startY] = true;

    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        if (x == endX && y == endY) return dist[x][y];

        for(int i = 0; i < 8; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if (newX >= 0 && newX < L && newY >= 0 && newY < L && !visited[newX][newY]) {
                Q.push({newX, newY});
                dist[newX][newY] = dist[x][y] + 1;
                visited[newX][newY] = true;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> L;
        
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;

        int result = bfs(startX, startY, endX, endY);
        cout << result << "\n";
    }

    return 0;
}