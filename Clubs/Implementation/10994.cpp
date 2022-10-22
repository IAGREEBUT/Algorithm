//<구현> -> 모르겠음
// 10994번 - 별찍기 19
// 실버 4

#include <iostream>
#include <vector>

using namespace std;


vector<vector<char>> drawStar(vector<vector<char>> star, int row, int col, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            if (i == 0 || i == size - 1)
                star[i + row][j + col] = '*';
            else if (j == 0 || j == size - 1)
                star[i + row][j + col] = '*';

        }
    }

    return star;

}


int main() {

    int n;
    cin >> n;

    //크기는 4n-3크기의 정사각형임
    vector<vector<char>> star(4 * n - 3, vector<char>(4 * n - 3, ' '));

    //사각형의 시작점
    int row = 0;
    int col = 0;
    int size = 4 * n - 3; //변의 길이
    // 한 단계 진행 시 마다 변의 길이는 양 사이드로 2씩 줄어들어서 크기는 4, col,row는 2씩 증가한 부분부터 시작함

    while (size >= 1) {
        star = drawStar(star, row, col, size);
        size -= 4;
        row += 2;
        col += 2;
    }

    for (int i = 0; i < 4 * n - 3; i++) {
        for (int j = 0; j < 4 * n - 3; j++) {

            cout << star[i][j];

        }
        cout << "\n";
    }

}
