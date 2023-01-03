//
// Created by 이유정 on 2023/01/03.
//

#include <iostream>
#include <vector>

using namespace std;

//북 동 남 서 -> 0 1 2 3 으로 지정되어 있으므로
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, 1, 0, -1};


int turnLeft(int dir) { //지금 바라보고있는 방향이 dir인 경우 이동해야하는 곳(row,col) 의 idx

    //북 -> 서 -> 남 -> 동 ( index -1 )

    if (dir - 1 < 0) return 3;
    return dir - 1;

}


int main() {

    int n, m;
    cin >> n >> m;

    int x, y, d; //캐릭터의 좌표, 바라보고있는 방향

    cin >> x >> y >> d;

    vector<vector<int>> map;
    map.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    map[x][y] = 2; //현재 위치 방문 처리


    int ans = 1;
    bool flag = false;

    while (true) {

        //1. 4가지 방향을 참고
        for (int i = 0; i < 4; i++) {
            cout << "---------------------------------\n";
            d = turnLeft(d);

            cout << "direction : " << d << "\n";

            //가보지 않은 칸이 존재하는지
            int nx = x + row[d];
            int ny = y + col[d];

            cout << "new block : " << nx << " " << ny << " " << map[nx][ny] << "\n";


            if (nx < n && nx >= 0 && ny >= 0 && ny < m && map[nx][ny] == 0) { //가보지 않은 "땅" 인 경우 -> 이동
                cout << "move\n";

                map[nx][ny] = 2; //가본 땅으로 표기를 변경
                x = nx;
                y = ny;
                ans++;//이동 횟수 증가
                flag = true;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << map[i][j] << " ";
                    }
                    cout << "\n";
                }
                break; //이동을 완료한 경우 반복문 탈출


            }

        }
        cout << "==================\n";
        cout << "==================\n";

        //4가지 방향을 전부 확인한 경우 (한번도 이동을 못하고 4방향을 전부 탐색함)
        if (!flag) {

            cout << "모든 방향을 전부 확인함\n";
            cout << "현재 방향 : " << d << "\n";

            int nd = (d + 2) % 4;


            cout << "뒷 방향 : " << nd << "\n";

            int nx = x + row[nd];
            int ny = y + col[nd];

            cout << "new block : " << nx << " " << ny << " " << map[nx][ny] << "\n";

            if (nx < n && nx >= 0 && ny >= 0 && ny < m && map[nx][ny] != 1) { //뒤로 이동 가능하면 이동
                cout << "뒤로 이동\n";
                x = nx;
                y = ny;
                //이미 가본칸으로 이동 하는 것 이기 때문에 ans를 증가시키지 않는다
            } else {
                break;//이동 불가능하면 종료
            }
        }
        flag = false; //flag 초기화
    }

    cout << ans;

}