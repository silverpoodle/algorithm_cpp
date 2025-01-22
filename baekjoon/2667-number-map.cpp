#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
정사각형 모양의 지도가 있다. 
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
대각선상에 집이 있는 경우는 연결된 것이 아니다. 
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

- 입력
    첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 
    그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

- 출력
    첫 번째 줄에는 총 단지수를 출력하시오. 
    그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

- 예제
    7
    0110100
    0110101
    1110101
    0000111
    0100000
    0111110
    0111000

    3
    7
    8
    9
*/

bool map[30][30];
bool visited[30][30] = {false};
int total = 0;
int cnt = 0;


int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};

int newX = 0; 
int newY = 0;

vector<int> cnt_vector;

void dfs(int x, int y) {

    visited[x][y] = true;
    cnt++;

    for(int i = 0 ; i < 4 ; i++) {
        newX = x + dirX[i];
        newY = y + dirY[i];

        if(map[newX][newY] && !visited[newX][newY]) {
            dfs(newX, newY);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; 
    cin >> N;

    for(int i = 1 ; i <= N ; i++) {
        string s;
        cin >> s;
        for(int j = 1 ; j <= N ; j++) {
            map[i][j] = s.at(j-1) == '1';
        }
    }

    for(int i = 1; i <= N ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            if(map[i][j] && !visited[i][j]){
                cnt = 0;
                dfs(i, j);
                cnt_vector.push_back(cnt);
                total ++;
            }
        }
    }
    cout << total << "\n";
    sort(cnt_vector.begin(), cnt_vector.end());
    for(int i = 0 ; i < cnt_vector.size() ; i++) {
        cout << cnt_vector[i] << "\n";
    }
    return 0;
}