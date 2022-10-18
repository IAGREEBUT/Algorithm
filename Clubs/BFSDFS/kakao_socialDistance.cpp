//
// Created by 이유정 on 2022/10/18.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 맨해튼 거리
 * (r1, c1) 과 (r2, c2)의 맨해튼 거리
 *  |r1 - r2| + |c1 - c2| < 2
 *
 *
 *
 *  1. 2 맨해튼 거리 이내로 앉기
 *  2. 2 맨해튼 거리 이내인 경우 파티션으로 막아있기
 *
 */

typedef pair<int, int> ii;
const int SIZE = 5;

//맨해튼 거리내에 모든 것을 탐색
int row[12] = {1, -1, 0, 0, 1, -1, 1, -1, 2, -2, 0, 0};
int col[12] = {0, 0, 1, -1, 1, -1, -1, 1, 0, 0, -2, 2};

vector<vector<int>> room;

bool bfs(ii start) {

    queue<ii> q;
    q.push(start);

    while (!q.empty()) { //입력 하나만 처리해도됨 (1회실행)


        int r = q.front().first;
        int c = q.front().second;

        q.pop();


        //맨해튼 거리를 전부 조사
        for (int i = 0; i < 12; i++) {
            int nr = r + row[i];
            int nc = c + col[i];

            //범위내에 있고 사람인 경우 -> 둘사이에 파티션이 존재하지 않는 이상 위반임
            if (nr >= 0 && nc >= 0 && nr < SIZE && nc < SIZE && room[nr][nc] == 1) { //1인 경우에만 검사

                //둘사이에 파티션이 존재하는가 (문제 그림 1번_
                if (i >= 8) { // idx 8보다 큰 경우에는 같은라인 2칸 떨어져있는 경우
                    if (room[(r + nr) / 2][(c + nc) / 2] != -1) {
                        return false; //지켜지지 않은 경우
                    }
                } else {//문제그림 2번
                    if (room[nr][c] != -1 || room[r][nc] != -1) { //둘중 하나라도 파티션이 없으면 끝
                        return false;
                    }
                }
            }


        }


    }

    return true;

}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // 1:사람 0: 빈자리 -1:벽or파티션


    for (int i = 0; i < places.size(); i++) {
        room.assign(SIZE, vector<int>(SIZE, -1));


        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (places[i][j].at(k) == 'P') {
                    room[j][k] = 1;
                } else if (places[i][j].at(k) == 'O') {
                    room[j][k] = 0;
                }
            }
        }

        //거리두기를 지키지 않은 사람의 존재 유무
        bool res = true;

        //사람을 발견하면 탐색 시작
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (room[i][j] == 1)
                    res = bfs({i, j});

                if (!res)//1명이라도 지키지 않으면 바로 break
                    break;
            }
            if (!res)break;//이중 for문 탈출을 위해
        }

        if (res) answer.push_back(1);
        else answer.push_back(0);

    }


    return answer;

}

int main() {
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                     {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                     {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                     {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                     {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> ans = solution(places);
    for (int i = 0; i < SIZE; i++)
        cout << ans[i] << ' ';
}