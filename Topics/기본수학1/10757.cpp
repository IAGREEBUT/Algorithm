/*
 * 백준 - 단계별 문제풀이 : 기본수학1
 * 10757번
 *
 * 큰 수 A + B
 *
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 *
 * Tip : string으로 변경해야함
 *
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main() {
    long long a, b;
    cin >> a >> b;

    string A, B;
    vector<int> C;
    A = to_string(a);
    B = to_string(b);

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    cout << A << "\n";
    cout << B << "\n";
    int Alen, Blen;

    Alen = A.length();
    Blen = B.length();


    if (Alen >= Blen) {

        bool flag = false;
        for (int i = 0; i < Blen; i++) {
            int aa, bb;
            aa = A.at(i) - '0';
            bb = B.at(i) - '0';

            cout << "aa : " << aa << "bb :" << bb << "\n";
            int tmp = aa + bb;

            cout << "tmp : " << tmp << "\n";

            if (flag == true) C.push_back(tmp % 10 + 1);
            else C.push_back(tmp % 10);

            if (tmp >= 10) flag = true;
            else flag = false;

        }

        for (int k = Blen; k < Alen; k++) {
            int tmp = A.at(k) - '0';

            cout << "2tmp : " << tmp << "\n";
            cout << "(tmp % 10 + 1) : " << tmp % 10 + 1 << "\n";
            cout << "tmp % 10 : " << tmp % 10 << "\n";

            if (flag == true) C.push_back(tmp % 10 + 1);
            else C.push_back(tmp % 10);

            if (tmp >= 10) flag = true;
            else flag = false;


        }

    }

    for (int j = 0; j < C.size(); j++) {

        cout << C[j];


    }

}