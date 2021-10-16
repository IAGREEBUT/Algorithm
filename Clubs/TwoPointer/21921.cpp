//
// 21921번 - 블로그
// [슬라이딩 윈도우] 방식 

#include <iostream>
#include <vector>

using namespace std;

vector<int> visitors;

int main() {

    int x, n;
    cin >> n >> x;

    visitors.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) { //0예외처리를 거르기 위해
        cin >> visitors[i];
    }


    //초기 설정
    // 1~x일까지의 방문자 수
    int sum = 0; // x일간의 방문자수
    int max = sum;// x일간의 방문자 수 중 최대
    int cnt = 1;// max값을 가지는 일이 몇번이나 나오는지
    for (int i = 1; i <= x; i++) {
        sum += visitors[i];
    }

    //위의 다음날부터 n일까지 x일간의 방문자수 구하기
    for (int i = x + 1; i <= n; i++) {
        sum = sum + visitors[i] - visitors[i - x]; // 새로운 날을 더하고, 맨 앞날을 빼 =>  총 x일로 유지
        if (max < sum) {//최댓값이 변경되면 갱신
            max = sum;
            cnt = 1;// 갯수는 1로초기화
        } else if (max == sum) cnt++; //갯수증가

    }


    if (max == 0) cout << "SAD";
    else cout << max << "\n" << cnt;


}