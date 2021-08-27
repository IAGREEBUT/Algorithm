/*
 * 백준 - 단계별 문제풀이 : for문
 * 8393번
 *
 * 합
 * n이 주어졌을 때, 1부터 n까지의 합을 구하는 프로그램을 작성하시오.
 *
 */

#include <iostream>

using namespace std;

int main() {


    int n;
    cin >> n;

    int res = 0; // c++의 지역변수 선언은 수 내 어디든 삽입이 가능하다

    for (int i = 1; i <= n; i++) {
        res += i;
    }

    cout << res;

}