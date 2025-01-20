#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
방향 없는 그래프가 주어졌을 때, 
연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

- 입력
    첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. 
    (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. 
    (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

- 출력
    첫째 줄에 연결 요소의 개수를 출력한다.

- 예제
    6 5
    1 2
    2 5
    5 1
    3 4
    4 6

    2
*/

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
int cnt = 0;

void check_graph(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = true;

    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                Q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {

    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0 ; i < M ; i++) {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            check_graph(i);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}