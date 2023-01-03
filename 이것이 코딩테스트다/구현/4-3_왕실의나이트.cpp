//
// Created by 이유정 on 2023/01/03.
//

#include <iostream>

using namespace std;

//상 좌 하 우
int row[4] = {0, 1, 0, -1};
int col[4] = {-1, 0, 1, 0};

bool isOnBoard(int r, int c) {

    if (r <= 7 && r >= 0 && c >= 0 && c <= 7) return true;
    return false;

}

int returnIdx(int idx) {
    if (idx < 0) return 3;
    return idx;
}


int main() {

    int ans = 0;
    string pos;
    cin >> pos;

    int r = pos.at(1) - '1';
    int c = pos.at(0) - 'a';


    int nr, nc;

    for (int i = 0; i < 4; i++) {

        //한 방향으로 2칸 선이동
        nr = r + 2 * row[i];
        nc = c + 2 * col[i];


        if (isOnBoard(nr, nc)) { //범위 내에 있는 경우

            //상,하 면 -> 우,좌 로 각각 한칸씩
            //우,좌 면 -> 상,하 로 각각 한칸씩
            // -> 아직도 범위 내에 있으면 갈 수 있는 곳

            int nrr = nr + row[returnIdx(i - 1)];
            int ncc = nc + col[returnIdx(i - 1)];
            if (isOnBoard(nrr, ncc)) ans++;


            nrr = nr + row[returnIdx(i + 1)];
            ncc = nc + col[returnIdx(i + 1)];
            if (isOnBoard(nrr, ncc)) ans++;

        }


    }

    cout << ans;


}