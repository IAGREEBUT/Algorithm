//
// Created by 이유정 on 2022/10/17.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

/*
 * "인접"한 곳에서 토마토가 익으므로 BFS
 */

vector<vector<int>> tomatoes;
queue<ii> q;

//상, 하, 좌, 우
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

int countTomato(int cnt) {

    if(cnt==0) return 0; //익어야할 토마토가 0개인 경우

    int ans = 0;
    int count = 0;

    while (!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;

        q.pop();


        //상하좌우 탐색
        for (int i = 0; i < 4; i++) {

            int nr = r + row[i];
            int nc = c + col[i];

            if (tomatoes[nr][nc] == 0) { //아직 안익은 토마토를 만난다면 -> 다음 차례에 익을 토마토
                q.push({nr, nc});// 익었으니까 큐에 넣어줌
                tomatoes[nr][nc] = tomatoes[r][c] + 1; // 영향 받은 칸의 수 + 1 (익은 날을 카운트)
                count++;//익은 토마토의 수
                ans = max(tomatoes[nr][nc], ans); //최댓값을 구하면됨
            }


        }


    }

    if (count != cnt) return -1; //익은 토마토의 수가 익어야할 토마토의 수와 다르면 -1

    return ans-1; //맨 첫번째 토마토가 1부터 시작했으므로

}


int main() {

    int m, n, num; // 가로x세로

    cin >> m >> n;

    tomatoes.assign(n + 2, vector<int>(m + 2, -1)); //상하좌우를 탐색하기 때문에 테두리를 -1로 만들어준다

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> num;
            tomatoes[i][j] = num;

            if (num == 1) { //익은 토마토인 경우 queue에 넣어서 시작정점을 미리 파악해두기
                q.push({i, j});
            } else if (num == 0) {
                cnt++; //익어야할 토마토의 갯수
            }

        }
    }


    cout << countTomato(cnt);

}