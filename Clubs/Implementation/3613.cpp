// 구현
// 3616번 - Java vs C++
// <실버 5>
// 문자열 변경하는 문제가 나오면 문자열 자체를 변경하려 하지말고 새로운 string을 만들어 채워넣는 방식을 써라


#include <iostream>

using namespace std;


bool isC(string str) {

    /*
     * 1. 대문자 불가능
     * 2. 연속된 __ 불가능
     * 3. 마지막에 _오는거 불가능
     *
     */

    if (!islower(str[0])) return false;


    for (int i = 1; i < str.length() - 1; i++) {

        if (isupper(str[i])) return false;
        if (str[i] == '_' && !islower(str[i + 1])) return false;

    }

    if (str[str.length() - 1] == '_') return false;

    return true;


}


bool isJava(string str) {

    /*
     * 1. _불가능
     */

    if (!islower(str[0])) return false;

    for (int i = 1; i < str.length(); i++) {

        if (str[i] == '_') return false;

    }


    return true;


}


string cToJava(string str) {
    int len = str.length();
    string ans = "";

    for (int i = 0; i < len; i++) {

        if (str.at(i) == '_') {
            ans.push_back(toupper(str[i + 1]));
            i++;
        } else {
            ans.push_back(str[i]);
        }


    }
    return ans;
}

string javaToC(string str) {
    int len = str.length();

    string ans = "";

    for (int i = 0; i < len; i++) {

        if (isupper(str[i])) {
            ans.push_back('_');
            ans.push_back(tolower(str[i]));
        } else {
            ans.push_back(str[i]);
        }
    }


    return ans;
}


int main() {

    string str;
    cin >> str;

    if (isC(str)) {
        cout << cToJava(str);
    } else if (isJava(str)) {
        cout << javaToC(str);
    } else {
        cout << "Error!";
    }


}
