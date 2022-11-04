// 구현, 시뮬
// 1244 - 스위치 켜고 끄기
// 실버 4

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n;
    cin >> n; //스위치의 수

    vector<bool> light;
    light.assign(n + 1, false);

    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == 1) light[i] = true;
    }

    int sn;//학생 수
    cin >> sn;

    int sex, num;
    while (sn--) {
        cin >> sex >> num; // 성별, 받은 번호

        if (sex == 1) {//남학생

            for (int i = num; i <= n; i += num) { //배수
                light[i] = !light[i];
            }


        } else {//여학생
            int left = num;
            int right = num;
            while (left >= 1 && right <= n) {
                if (light[left] != light[right]) break;
                left--;
                right++;
            }

            for (int i = left + 1; i <= right - 1; i++) { //일치하지 않는 곳에서 멈췄으므로 한칸 앞으로
                light[i] = !light[i];
            }

        }


    }


    for (int i = 1; i <= n; i++) {
        cout << light[i] << " ";
        if (i % 20 == 0) cout << "\n"; //출력형식
    }

}