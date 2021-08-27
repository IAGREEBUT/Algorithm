/*
 * 백준 - 단계별 문제풀이 : for문
 * 2742번
 *
 * 기찍 N
 * 자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>

using namespace std;

int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리

    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {
        cout << i << "\n";
    }
}