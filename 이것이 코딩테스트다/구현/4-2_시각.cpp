//
// Created by 이유정 on 2023/01/03.
//

#include <iostream>
#include <string>


using namespace std;

/*
 * 시간 복잡도
 *  N+1(0시부터 N시까지)  * 60(0분 ~ 59분) * 60 (0초~ 59초) = 3600N + 3600
 *  -> O(N)
 *
 *  N의 max = 24이므로 전부 탐색해도 90000이하임
 *
 *  -> 완전탐색
 *
 */


int main() {

    int ans = 0;
    int n;
    cin >> n;


    for (int i = 0; i <= n; i++) {


        for (int j = 0; j < 60; j++) {

            for (int k = 0; k < 60; k++) {


                string h = to_string(i);
                string m = to_string(j);
                string s = to_string(k);

                string time = h + m + s;

                if (time.find("3") != string::npos) ans++; //3이 존재하면 1증가


            }


        }


    }

    cout << ans << "\n";


    int ans2 = 0;

    for (int i = 0; i <= n; i++) {//시

        if (i == 3 || i == 13 || i == 23) {
            ans2 += 3600;
            continue;
        }

        for (int j = 0; j < 60; j++) {//분

            if (j == 3 || j == 13 || j == 23 || j == 43 || j == 53) {
                ans2 += 60;
                continue;
            } else if (j >= 30 && j <= 39) {
                ans2 += 60;
                continue;
            }


            for (int k = 0; k < 60; k++) {//초

                if (k == 3 || k == 13 || k == 23 || k == 43 || k == 53) {
                    ans2++;
                } else if (k >= 30 && k <= 39) {
                    ans2++;
                }

            }


        }


    }


    cout << ans2;


}
