/*
 * 백준 - 단계별 문제풀이 : if문
 * 1330번
 *
 * 두 수 비교하기
 * 두 정수 A와 B가 주어졌을 때, A와 B를 비교하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <string> // string 사용을 위해

std::string solution(int A, int B) {

    if (A > B)
        return ">";
    else if (A < B)
        return "<";
    else
        return "==";
}

int main() {

    // 두 정수 A,B 입력
    int A, B;
    std::cin >> A >> B;


    std::cout << solution(A, B) << std::endl;
    return 0;
}




