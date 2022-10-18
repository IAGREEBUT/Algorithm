//
// Created by 이유정 on 2022/10/13.
//

#include <iostream>


using namespace std;

/*
 * n과 m (1)
 * 자연수 n이 주어졌을 때 길이가 m인 수열
 * 조건 : 1 ~ n까지 수 중에 중복없이 m개를 고름
 *
 */

const int SIZE = 9;
int arr[SIZE];
bool checked[SIZE];
int n, m;

void backtracking(int cnt) { // 현재까지 배열에 들어간 숫자의 갯수 (m개가 되면 종

    //기저 조건료
    // 모인 카드의 수가 m개인가
    if (cnt == m) {

        //num에 저장된 배열을 출력
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        return;
    }


    for (int j = 1; j <= n; j++) {
        if (!checked[j]) {//j가 사용된적 없을 때 만
            arr[cnt] = j;  //정답 배열에 수 삽입
            checked[j] = true;//사용상태로 변경
            backtracking(cnt + 1); //다음 탐색을 진행
            checked[j] = false; //사용 이전상태로 되돌림

        }
    }

}


int main() {

    cin >> n >> m;

    backtracking(0);


}