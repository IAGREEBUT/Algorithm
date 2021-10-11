/*
 * 백준 - 단계별 문제풀이 : for문
 * 2741번
 *
 * N 찍기
 * 자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i << "\n";
    }

}