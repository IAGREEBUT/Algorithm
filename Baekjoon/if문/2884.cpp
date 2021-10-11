/*
 * 백준 - 단계별 문제풀이 : if문
 * 14681번
 *
 * 알람 시계
 * 알람을 일어나려는 시간보다 45분 일찍 설정하려고 한다.
 * 현재 설정한 알람 시각이 주어졌을 떄, 45분 이전으로 고쳐주는 프로그램을 작성하시오.
 *
 */

#include <iostream>

void solution(int h, int m) {

    int min = m - 45;
    int hour;

    if (min >= 0) {
        std::cout << h << " " << min << std::endl;
    } else {
        min = 60 + min;
        hour = h - 1;
        if (hour < 0) hour = 23;

        std::cout << hour << " " << min << std::endl;
    }

}

int main() {

    //일어나려는 시각 ( h m )
    int h, m;
    std::cin >> h >> m;

    solution(h, m);
}
