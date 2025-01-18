#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.
정점 번호는 1번부터 N번까지이다.

- 입력
    첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
    다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
    어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
    입력으로 주어지는 간선은 양방향이다.

- 출력
    출첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
    V부터 방문된 점을 순서대로 출력하면 된다.

- 예제
    4 5 1
    1 2
    1 3
    1 4
    2 4
    3 4

    1 2 4 3
    1 2 3 4


    5 5 3
    5 4
    5 2
    1 2
    3 4
    3 1

    3 1 2 5 4
    3 1 4 2 5   
*/


void sort(vector<int> &list) {
    for(int i = 0 ; i < list.size() ; i++) {
        for(int j = i+1 ; j < list.size() ; j++) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    cout << node << " ";
    visited[node] = true;

    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

void bfs(int start, vector<vector<int>> &graph) {
    queue<int> Q;
    vector<bool> visited(graph.size(), false);

    Q.push(start);
    visited[start] = true;

    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        cout << node << " ";

        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                Q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);

    for(int i = 0 ; i < M ; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1 ; i <= N ; i++) {
        sort(graph[i]);
    }

    vector<bool> visited(N + 1, false);
    dfs(V, graph, visited);
    cout << "\n";

    bfs(V, graph);
    cout << "\n";

    return 0;
}