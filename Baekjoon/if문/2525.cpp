//
// Created by 이유정 on 2022/08/31.
//

#include <iostream>

using namespace std;


int main() {

    int start_h, start_m, time; // 시작시간과 걸리는 시간
    int res_h, res_m;//결과 값


    cin >> start_h >> start_m >> time;

    if (start_m + time >= 60) { // 60분 초과시

        res_h = start_h + (start_m + time) / 60;
        res_m = (start_m + time) % 60;

    } else {
        res_h = start_h;
        res_m = start_m + time;
    }

    cout << res_h % 24 << " " << res_m; //24시간으로 나누어줘야함


}