// 구현
// 3190 - 뱀
// 골드 5


#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;
typedef pair<int, char> ic;
typedef pair<int, int> ii;

//우 -> 하 -> 좌 -> 상 (오른쪽 90도씩 회전)
int row[4] = {0, 1, 0, -1};
int col[4] = {1, 0, -1, 0};

int main() {

    int n, k, l;

    cin >> n >> k;

    vector<vector<int>> board(n + 2, vector<int>(n + 2, 0));
    board[1][1] = 3; //뱀

    //테투리
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1) board[i][j] = 3;
        }
    }

    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        board[r][c] = 2; //사과
    }

    queue<ic> snake_dir;
    int x;
    char d;

    cin >> l;
    while (l--) {
        cin >> x >> d;
        snake_dir.push({x, d});
    }

    int time = 0;
    int dir = 0;//방향 index

    //front (head)----(tail) back
    deque<ii> snake;
    snake.push_back({1, 1});


    while (true) {

        time++; //이동전에 시간을 변경해줘야 break당해도 시간 변경이 적용됨

        //뱀의 머리 위치
        int r = snake.front().first;
        int c = snake.front().second;

        //머리의 이동 위치
        int nr = r + row[dir];
        int nc = c + col[dir];


        if (board[nr][nc] == 2) { //사과
            board[nr][nc] = 3; //사과를 없애고 그자리로 이동
            snake.push_front({nr, nc}); //머리를 넣기 + 꼬리 뺴지 않음
        } else if (board[nr][nc] == 0) {
            board[nr][nc] = 3; //이동
            snake.push_front({nr, nc}); //새로운 칸의 머리 넣기
            board[snake.back().first][snake.back().second] = 0; //꼬리가 있던 자리 0으로 변경
            snake.pop_back();//꼬리 빼기
        } else if (board[nr][nc] == 3) {//자신의 몸 or 벽 (게임 종료)
            break;
        }


        //다음 초 부터 방향전환이 적용되기 때문에 마지막에 확인하기
        if (snake_dir.front().first == time) {//방향을 이동해야할 시간

            if (snake_dir.front().second == 'D') {//오른쪽으로 90도
                dir = (dir + 1) % 4;
            }
            if (snake_dir.front().second == 'L') {//왼쪽으로 90도
                if (dir - 1 < 0) {
                    dir = 3;
                } else {
                    dir--;
                }
            }

            snake_dir.pop();

        }


    }


    cout << time;

}

