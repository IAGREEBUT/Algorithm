// <구현>
// 10757번 - 큰 수 A + B
// 브론즈 5


#include <iostream>
#include <string>

using namespace std;

int main() {

    string a, b;

    cin >> a >> b;

    //마지막 자
    int len_a = a.length() - 1;
    int len_b = b.length() - 1;

    string ans = "";

    int charge = 0;

    while (len_a >= 0 && len_b >= 0) {

        int aa = a.at(len_a) - '0';
        int bb = b.at(len_b) - '0';


        char value = ((aa + bb + charge) % 10) + '0';
        ans.push_back(value);
        charge = (aa + bb + charge) / 10; //올림 숫자


        len_a--;
        len_b--;
    }

    while (len_a >= 0) {
        int aa = a.at(len_a) - '0';
        char value = ((aa + charge) % 10) + '0';
        ans.push_back(value);
        charge = (aa + charge) / 10;
        len_a--;
    }

    while (len_b >= 0) {
        int bb = b.at(len_b) - '0';
        char value = ((bb + charge) % 10) + '0';
        ans.push_back(value);
        charge = (bb + charge) / 10;
        len_b--;
    }

    if (charge > 0) ans.push_back(charge + '0');


    for (int i = ans.length() - 1; i >= 0; i--) {
        cout << ans[i];
    }


}
