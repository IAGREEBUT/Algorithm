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

//    cout << A << "\n";
//    cout << B << "\n";
    int Alen, Blen;

    int aa, bb, add_tmp, tmp;

    Alen = A.length();
    Blen = B.length();

    bool flag = false;
    if (Alen >= Blen) {

        for (int i = 0; i < Blen; i++) {
//            int aa, bb;
            aa = A.at(i) - '0';
            bb = B.at(i) - '0';

//            cout << "aa : " << aa << "bb :" << bb << "\n";
            tmp = aa + bb;

//            cout << "tmp : " << tmp << "\n";

//            int add_tmp;


//            if (flag == true) C.push_back(tmp % 10 + 1);
//            else C.push_back(tmp % 10);

            if (flag == true) add_tmp = tmp + 1;
            else add_tmp = tmp;

            if (add_tmp >= 10) flag = true;
            else flag = false;

            C.push_back(add_tmp % 10);
            cout << "flag : " << flag << "\n";

        }

        for (int k = Blen; k < Alen; k++) {
            int tmp = A.at(k) - '0';

            cout << "2tmp : " << tmp << "\n";
            cout << "(tmp % 10 + 1) : " << tmp % 10 + 1 << "\n";
            cout << "tmp % 10 : " << tmp % 10 << "\n";
            cout << flag << "\n";

//            if (flag == true) C.push_back(tmp % 10 + 1);
//            else C.push_back(tmp % 10);
//
//            if (tmp >= 10) flag = true;
//            else flag = false;

            if (flag == true) add_tmp = tmp + 1;
            else add_tmp = tmp;

            if (add_tmp >= 10) flag = true;
            else flag = false;

            C.push_back(add_tmp % 10);


        }

        if (flag == true) C.push_back(1);

    }

    for (int j = C.size() - 1; j >= 0; j--) {

        cout << C[j];


    }

}