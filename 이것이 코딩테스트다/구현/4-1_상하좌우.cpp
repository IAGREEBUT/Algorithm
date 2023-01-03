//
// Created by 이유정 on 2023/01/03.
//

#include <iostream>

using namespace std;

typedef pair<int, int> ii;


// 왼, 오, 위, 아래
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, -1, 1};
char plans[4] = {'L', 'R', 'U', 'D'};

int main() {

    int n;
    cin >> n;


    int r = 1, c = 1;


    char d;
    while (true) {
        cin >> d;
        if (cin.eof() == true) break;

        for (int i = 0; i < 4; i++) {
            if (d == plans[i]) {
                int n_r = r + row[i];
                int n_c = c + row[i];

                //범위 내에 있을 때만 이동
                if (n_r >= 1 && n_r <= n) r = n_r;
                if (n_c >= 1 && n_c <= n) c = n_c;
            }
        }

    }

    cout << r << " " << c;

}

