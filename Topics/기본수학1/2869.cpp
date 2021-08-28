/*
 * 백준 - 단계별 문제풀이 : 기본수학1
 * 2869번
 *
 * 달팽이는 올라가고 싶다.
 * 땅 위에 달팽이가 있다. 이 달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다.
 * 달팽이는 낮에 A미터 올라갈 수 있다.
 * 하지만, 밤에 잠을 자는 동안 B미터 미끄러진다. 또, 정상에 올라간 후에는 미끄러지지 않는다.
 * 달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int solution(int v, int a, int b) {

    int h = 0;
    int day = 1;

    while (true) {

        h += a;
        if (h >= v) break;

        h -= b;
        day++;

    }

    return day;

}

int main() {


    int A, B, V;
    cin >> A >> B >> V;

    int sol;
    sol = ceil(V - A / (A - B));


    cout << sol + 1 << "\n";


}