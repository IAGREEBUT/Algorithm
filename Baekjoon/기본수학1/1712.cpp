/*
 * 백준 - 단계별 문제풀이 : 기본수학1
 * 1712번
 *
 * 손익분기점
 * 월드 전자는 노트북을 제조하고 판매하는 회사이.
 * 노트북 판매 대수에 상관없이 매년 A만원의 고정비용이 들며,
 * 한대의 노트북을 생산하는데 재료비, 인건비 등 총 B만원의 가변비용이 든다.
 * 노트북 가격이 C로 측정되었을 때,
 * A,B,C를 입력받아 손익분기점을 구하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <cmath>

using namespace std;


int solution(int a, int b, int c) {

    if (c - b <= 0) return -1;
    else {
        return floor(a / (c - b) + 1);
    }

}


int main() {

    int a, b, c;
    cin >> a >> b >> c;

    cout << solution(a, b, c) << "\n";

}