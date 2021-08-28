/*
 * 백준 - 단계별 문제풀이 : 기본수학1
 * 1193번
 *
 * 분수찾기
 * 이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은
 * 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
 * X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
 *
 */

#include <iostream>

using namespace std;

void solution(int x) {

    int m;
    int n = 1;
    int min, max;
    int a, b;

    if (x == 1) {
        cout << "1/1" << "\n";
        return;
    }

    while (true) {

        min = 1 + n * (n - 1) / 2;
        max = n * (n + 1) / 2;

        if (min <= x && max >= x) break;
        n++;

    }

    m = x - min;


    a = 1 + m;
    b = n - m;

    cout << a << "/" << b << "\n";

}

int main() {

    int x;
    cin >> x;

    solution(x);

}