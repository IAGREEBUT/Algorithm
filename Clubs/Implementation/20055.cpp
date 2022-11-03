// 구현,시뮬레이
// 20055 - 컨베이어 벨트 위의 로봇
// 골드

#include <iostream>
#include <vector>

using namespace std;


/*
 * 0. 어떤 단계에 있든 내리는 위치에 로봇이 도달하면 로봇을 내린다!
 * 1. 벨트의 이동(로봇포함)
 * 2. 올라탄 순서대로 "로봇"이동 -> 내구도가 1이상 / 한칸에 로봇 1개만 가
 * 3. 내구도가 0이 아니면 올리는 자리에 로봇 올리기
 * 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
 */



int checkZeroDur(vector<int> &dur, int n) {
    //벨트중 0의 갯수를 count
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (dur[i] == 0) cnt++;
    }

    return cnt;

}

int moveIndex(int n, int idx) {
    //벨트가 앞으로 이동하므로, 포인터는 뒤로 이동해야함
    return (idx - 1 >= 0 ? idx - 1 : 2 * n - 1);

}

int main() {
    int n, k;
    cin >> n >> k;

    int on = 0, off = n - 1;//올리는 칸, 내리는 칸을 가리키는 포인터
    vector<int> dur(2 * n, 0);//내구도 저장
    vector<bool> robot(2 * n, false); //로봇의 존재여부를 확인

    for (int i = 0; i < 2 * n; i++) {
        cin >> dur[i];
    }


    int ans = 1;//첫 단계는 1단게
    while (true) {

        //1단계 :
        // (1)벨트 이등 -> 실제 벨트 이동보다는 포인터 이동이 나음
        on = moveIndex(n, on);
        off = moveIndex(n, off);


        if (robot[off]) {
            robot[off] = false;
        }

        //2단계
        int idx = off;
        while (idx != on) { // off -> on칸부터 검사

            idx = moveIndex(n, idx);

            if (robot[idx]) {

                int next = (idx + 1) % (2 * n);

                if (!robot[next] && dur[next] >= 1) {
                    //idx칸에 로봇 존재 & 다음 칸에 로봇없음 && 다음 칸 내구성 1이상
                    robot[idx] = false;
                    dur[next]--; //내구도 감소

                    if (next != off) { //다음 칸이 off칸이면 내려지므로 굳이 true로 변경할 이유가 없음
                        robot[next] = true;
                    }
                }
            }


        }


        //3단계 :
        if (!robot[on] && dur[on] >= 1) {
            robot[on] = true;
            dur[on]--;
        }


        //4단계
        if (checkZeroDur(dur, n) >= k) break;
        ans++;

    }

    cout << ans;


}