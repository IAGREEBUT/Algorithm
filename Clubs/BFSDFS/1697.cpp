//
// 범위검사가 까다로운 문제
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 100000;
vector<int> board;

int findSister(int n, int k) {

    if (n == k) return 0;


    queue<int> q;
    q.push(n);

    while (!q.empty()) {

        int me = q.front();
        q.pop();

        if (me == k) {
            return board[me] - 1; //시작위치 1이라 빼줘야함
        }

        vector<int> child = {me + 1, me - 1, me * 2};
        for (int i = 0; i < 3; i++) {
            if (child[i] >= 0 && child[i] <= SIZE &&
                board[child[i]] == 0) { //범위를 먼저 검사해야함!! 아니면 outofBound . 0이면 첫방문 (범위내에 있어야함)
                board[child[i]] = board[me] + 1;
                q.push(child[i]);
            }
        };


    }


}


int main() {

    int n, k;
    board.assign(SIZE + 1, 0);

    cin >> n >> k;
    board[n] = 1; //시작한 위치를 1로 초기화


    cout << findSister(n, k); // n이 0일 경우를 고려하여 한칸 -1 되더라도 정상작동하도록...


}