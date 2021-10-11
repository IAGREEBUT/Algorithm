/*
 * 백준 - 단계별 문제풀이 : for문
 * 2739번
 *
 * 구구단
 * N을 입력받은 뒤, 구구단 N단을 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>

void solution(int n) {

    int res;

    for (int i = 1; i < 10; i++) {
        res = n * i;
        std::cout << n << " * " << i << " = " << res << std::endl;
    }


}

int main() {

    // n단 입력받기
    int n;
    std::cin >> n;

    solution(n);

    return 0;
}
