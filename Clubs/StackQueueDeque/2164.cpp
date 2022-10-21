//
// 2164번 - 카드2 (deque)
//

#include <iostream>
#include <deque>

using namespace std;

int main() {

    int n;
    cin >> n;

    deque<int> q;

    while (n > 0) {
        q.push_front(n--);
    }

    while (q.size() > 1) {
        q.pop_front();
        q.push_back(q.front());
        q.pop_front();
    }

    cout << q.front();

}