//<구현>
// 19636번 - 요요 시뮬레이션
// 실버 5

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 체중(w)
 * 다이어트 전 : bw
 *
 * 일일 에너지 섭취량 = 일일 기초대사량 (l)
 * 다이어트 전 : bl
 * 다이어트 중 : l
 *
 * 일일 기초 대사량(L)
 * 다이어트 전 : BL(=bl)
 * 다이어트 중 : L
 *
 * 일일 활동 대사량 (a)
 * 다이어트 전 : 0
 * 다이어트 중 : a
 *
 * 다이어트 기간 (d)
 *
 *
 * 변화 값
 * 체중 :
 * w += 일일 에너지 섭취량(l) - 일일 에너지 소비량( l + a )
 *
 * 일일 기초 대사량 :
 * if( l - a > t ) then L += floor( (l-a)/2 )
 *
 *
 *
 */


int main() {

    int bw, bl, t, d, l, a;

    cin >> bw >> bl >> t;
    cin >> d >> l >> a;

    int w1 = bw, w2 = bw;
    int L = bl;

    for (int i = 0; i < d; i++) {
        w1 += l - bl - a;
        if (w1 <= 0) {
            cout << "Danger Diet\n";
            break;
        }
    }

    if (w1 > 0) cout << w1 << " " << bl << "\n";


    for (int i = 0; i < d; i++) {

        w2 += l - L - a;

        if (w2 <= 0) {
            cout << "Danger Diet\n";
            break;
        }

        if (abs(l - L - a) > t)
            L += floor((double) (l - L - a) / 2.0);

        if (L <= 0) {
            cout << "Danger Diet\n";
            break;
        }

    }

    if (w2 > 0 && L > 0) {
        cout << w2 << " " << L << " ";

        if (bl - L > 0) cout << "YOYO";
        else cout << "NO";
    }


}