//
// Created by 이유정 on 2022/08/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n; // 테스트 케이스의 갯수
    string ox;// 테스트 케이스(한줄)

    for (int i = 0; i < n; i++) { //테스트 케이스의 수만큼 반복

        cin >> ox; //입력받기

        int numOfO = 0; // 연속되는 O의 갯수
        int score = 0; // 최종 점수
        for (int i = 0; i < ox.length(); i++) { //테스트 케이스의 길이만큼 반복

            if (ox.at(i) == 'O') { //맞은 경우
                numOfO++;//연속되는 o의 갯수 증가
                score += numOfO;//점수 추가
            } else {
                numOfO = 0;//연속되는 o의 갯수 초기화
            }

        }

        cout << score << "\n";


    }


}