//
// Created by 이유정 on 2022/10/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * W = TRUE
 * B = FALSE
 *
 * 만들수 있는 체스판의 종류는 두가지
 * WBWB...W로 시작하는 판
 *
 * BWBW ... B로 시작하는 판
 * -> 둘은 정 반대이기 때문에 하나만 검사 한 후 8*8 - (검사한 수) = 다른 보드판을 기준으로 했을 때 수
 *
 */

int countBlock(vector<vector<bool>> board, int i, int j) {

    int cnt = 0;//바꿔야할 타일의 수
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {

            int loc = i + x + j + y;//음수면 B, 짝수면 W가 될 때 올바른 색임
            //W로 시작
            if (loc % 2 == 0 && !board[x + i][y + j]) { //짝수 칸인데 해당칸이 B인 경우
                cnt++;
            } else if (loc % 2 != 0 && board[x + i][y + j]) {//음수 칸인데 해당 칸이 W인 경우
                cnt++;
            }


        }
    }

    return cnt;

}


int solution(vector<vector<bool>> board, int n, int m) {

    int ans = 64;// 8*8보드판을 전부 편경해야하는 경우

    //보드판을 n-8까지 검사 (이유: 체스판의 크기가 8이라서 마지막 시작지점에서 시작해도 8칸은 확보 필수
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {

            int v = countBlock(board, i, j);

            ans = min({ans, v, 64 - v});// v:W로 시작하는 체스판의 경우 64-v : B로시작하는 체스판의 경우

        }
    }

    return ans;

}


int main() {

    int n, m;

    cin >> n >> m;



    //board setting
    vector<vector<bool>> board;
    board.assign(n, vector<bool>(m, false));
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s.at(j) == 'W')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }

    cout << solution(board, n, m);

}