// 구현, 비트마스킹
// 11723 - 집합
//

#include <iostream>

using namespace std;
const int SIZE = 21;

/* <비트 마스킹>
 * true = 1 , false = 0로 생각하고 이진수로 표현한다고 생각하는 개념
 * 0000 0000 0000 0000 0010 = {1} => 값은 2  ( 1 << num ) num : 원소 이렇게 해야해서 어쩔수없다!
 * 0001 1111 1111 1111 1110 = {20}
 *
 *
 */



int main() {


    int m, num;
    string str;
    int s = 0;
    cin >> m;

    while (m--) {
        cin >> str;
        if (str == "all") {
            s = (1 << SIZE) - 1;
            // 0010 0000 0000 0000 0000 - 1
            // 0001 1111 1111 1111 1111
            continue;
        }
        if (str == "empty") {
            s = 0;
            continue;
        }

        cin >> num;
        if (str == "add") {
            s |= (1 << num); // num자리를 1로 변경
            continue;
        }
        if (str == "remove") {
            s &= ~(1 << num); // num자리를 0으로 변경 (1->0 , 0->0)
            continue;
        }
        if (str == "check") {
            int tmp = s & (1 << num);
            cout << ((tmp == 0) ? 0 : 1) << '\n';
            continue;
        }
        if (str == "toggle") {
            s ^= (1 << num);
            continue;
        }

    }


}