#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
영선이는 숫자가 쓰여 있는 직사각형 종이를 가지고 있다. 종이는 1×1 크기의 정사각형 칸으로 나누어져 있고, 
숫자는 각 칸에 하나씩 쓰여 있다. 행은 위에서부터 아래까지 번호가 매겨져 있고, 
열은 왼쪽부터 오른쪽까지 번호가 매겨져 있다.

영선이는 직사각형을 겹치지 않는 조각으로 자르려고 한다. 
각 조각은 크기가 세로나 가로 크기가 1인 직사각형 모양이다. 
길이가 N인 조각은 N자리 수로 나타낼 수 있다. 가로 조각은 왼쪽부터 오른쪽까지 수를 이어 붙인 것이고, 
세로 조각은 위에서부터 아래까지 수를 이어붙인 것이다. 
종이를 적절히 잘라서 조각의 합을 최대로 하는 프로그램을 작성하시오.

첫째 줄에 종이 조각의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 4)
둘째 줄부터 종이 조각이 주어진다. 각 칸에 쓰여 있는 숫자는 0부터 9까지 중 하나이다.
*/


int N, M;
vector<string> paper;
int answer = 0;

int calculate(vector<vector<bool>>& pieces) {
    int sum = 0;
    
    //가롱
    for(int i = 0; i < N; i++) {
        int temp = 0;
        for(int j = 0; j < M; j++) {
            if(!pieces[i][j]) { //가로조각일때

                //현재는 문자열 -> 숫자로 변환
                temp = temp * 10 + (paper[i][j] - '0');
            } else { //세로 조각 만나면
                sum += temp;
                temp = 0;
            }
        }
        sum += temp;
    }
    
    //세로
    for(int j = 0; j < M; j++) {
        int temp = 0;
        for(int i = 0; i < N; i++) {
            if(pieces[i][j]) { 
                temp = temp * 10 + (paper[i][j] - '0');
            } else {
                sum += temp;
                temp = 0;
            }
        }
        sum += temp; 
    }
    
    return sum;
}

void solve() {

    // (1 << k) 는 2^k를 계산하는 비트 연산
    for(int state = 0; state < (1 << (N * M)); state++) {
        vector<vector<bool>> pieces(N, vector<bool>(M));

        for(int i = 0; i < N; i++) { 
            for(int j = 0; j < M; j++) {
                // bit 가 1인자 확인
                if(state & (1 << (i * M + j))) {
                    pieces[i][j] = true;
                }
            }
        }
        

        int sum = calculate(pieces);
        answer = max(answer, sum);
    }
}

int main() {
    cin >> N >> M;
    paper.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> paper[i];
    }
    
    solve();
    cout << answer << endl;
    
    return 0;
}