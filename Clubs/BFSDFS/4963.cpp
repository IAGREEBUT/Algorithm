//
// Created by 이유정 on 2022/10/18.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

vector<vector<bool>> visited;
vector<vector<int>> board;
queue<ii> q;

//오른쪽으로 45도씩
//상->
int row[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};


int bfs(ii start, int cnt) {


    q.push(start);
    visited[start.first][start.second] = true;
    cnt--;


    while (!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;


        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + row[i];
            int nc = c + col[i];

//            cout << "큐 후보 : " << nr << " " << nc << "\n";

            if (!visited[nr][nc] && board[nr][nc] == 1) {
                q.push({nr, nc});
                visited[nr][nc] = true; //visited 를 안에다가 해줘야 메모리를 덜 사용한다
                cnt--;
            }

        }


    }

    return cnt;


}


int main() {

    int w, h, num;

    int cnt = 0; //1의 갯수
    int ans = 0;//섬의 갯수

    while (true) {

        cin >> w >> h;
        ans = cnt = 0;

        if (w == 0 && h == 0) break;

        board.assign(h + 2, vector<int>(w + 2, 0)); //
        visited.assign(h + 2, vector<bool>(w + 2, false));


        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {

                cin >> num;
                board[i][j] = num;

                if (num == 1) {
                    cnt++;
                }

            }
        }

        if (cnt == 0) cout << 0 << "\n";

//        cout << " 탐색  끝 섬의 갯수 : " << ans << "\n";
//        cout << " 시작전 남은 땅의 수 : " << cnt << "\n";


        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {

                if (!visited[i][j] && board[i][j] == 1) { //섬을 탐색


//                    cout << " 탐색 start : " << i << " " << j << "\n";

                    cnt = bfs({i, j}, cnt);
                    ans++;

                    if (cnt == 0) {
                        cout << ans << "\n";
                        break;
                    }
//                    cout << " 탐색  끝 섬의 갯수 : " << ans << "\n";
//                    cout << " 남은 땅의 수 : " << cnt << "\n";

                }


            }
        }


    }


}