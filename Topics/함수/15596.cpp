/*
 * 백준 - 단계별 문제풀이 : 함수
 * 15596번
 *
 * 정수 N개의 합
 * 정수 n개가 주어졌을 때, n개의 합을 구하는 함수를 작성하시오.
 *
 */

#include <iostream>
#include <vector>

using namespace std;


long long sum(vector<int> &a) {

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {

        sum += a[i];
    }
    return sum;

}

