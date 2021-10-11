/*
 * 백준 - 단계별 문제풀이 : if문
 * 14681번
 *
 * 사분면 고르
 * 점의 좌표를 입력받아 그 점이 어느 사분면에 속하는지 알아내는 프로그램을 작성하시오.
 * 단, x좌표와 y좌표는 모두 양수나 음수라고 가정한다.
 *
 */

#include <iostream>

int solution(int x, int y) {
    if (x > 0) { // 1,4
        if (y > 0) return 1;
        else return 4;
    } else {
        if (y > 0) return 2;
        else return 3;
    }
}


int main() {

    // x좌표, y좌표 입력받기
    int x, y;
    std::cin >> x >> y;

    std::cout << solution(x, y) << std::endl;
}
