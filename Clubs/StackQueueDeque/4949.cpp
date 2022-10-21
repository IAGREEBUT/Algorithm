//
// 4949 - 균형잡힌 세상 (스택)
//

#include <iostream>
#include <stack>

using namespace std;


bool isEven(string input) {

    stack<char> s;


    for (int i = 0; i < input.length(); i++) {

        char c = input.at(i);

        if (c == '(' || c == '[') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        } else if (c == ']') {
            if (s.empty() || s.top() != '[') return false;
            s.pop();
        }


    }

    if (s.empty()) return true;
    return false;


}


int main() {

    string input;

    while (true) {

        getline(cin, input);

        if (input == ".")break;


        cout << (isEven(input) ? "yes\n" : "no\n");


    }

}