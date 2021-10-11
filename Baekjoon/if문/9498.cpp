/*
 * 백준 - 단계별 문제풀이 : if문
 * 9498번
 *
 * 시험 성
 * 시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B,
 * 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>

char solution(int score) {

    if (score >= 90 && score <= 100)
        return 'A';
    else if (score >= 80 && score <= 89)
        return 'B';
    else if (score >= 70 && score <= 79)
        return 'C';
    else if (score >= 60 && score <= 69)
        return 'D';
    else
        return 'F';
}


int main() {

    //시험 점수 입력
    int score;
    std::cin >> score;

    std::cout << solution(score) << std::endl;

    return 0;
}