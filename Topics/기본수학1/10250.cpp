/*
 * 백준 - 단계별 문제풀이 : 기본수학1
 * 10250번
 *
 * ACM 호텔
 *
 * 문제참고
 * https://www.acmicpc.net/problem/10250.
 *
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main() {

    int n;
    int h, w, num;
    int x, y;

    vector<string> res;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> w >> num;

        y = ceil((double) num / (double) h);
        x = num % h;

        if (x == 0) x = h;

        string yy = to_string(y);
        string xx = to_string(x);


        if (y < 10) res.push_back(xx + "0" + yy);
        else res.push_back(xx + yy);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }


}