//
// Created by 이유정 on 2023/01/03.
//


#include <iostream>

using namespace std;

//L모양으로 이동 가능한 8가지 경우
int row[8] = {-1, 1, -1, 1, 2, 2, -2, -2};
int col[8] = {-2, -2, 2, 2, -1, 1, -1, 1};

bool isOnBoard(int r, int c) {

    if (r <= 7 && r >= 0 && c >= 0 && c <= 7) return true;
    return false;

}

int main() {

    int ans = 0;
    string pos;
    cin >> pos;

    int r = pos.at(1) - '1';
    int c = pos.at(0) - 'a';


    int nr, nc;

    for (int i = 0; i < 8; i++) {

        nr = r + row[i];
        nc = c + col[i];

        if (isOnBoard(nr, nc)) ans++;

    }

    cout << ans;


}