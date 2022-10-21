


#include <iostream>
#include <set>

using namespace std;

int main() {

    int n, num;
    set<int> s;

    cin >> n;

    while (n--) {
        cin >> num;
        s.insert(num);
    }


    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << " ";
    }

}








//
//#include <iostream>
//#include <set>
//
//using namespace std;
//
//int main() {
//    int n, k;
//    set<int> s;
//
//    //입력
//    cin >> n;
//    while (n--) {
//        cin >> k;
//        s.insert(k);
//    }
//
//    //출력
//    for (auto iter = s.begin(); iter != s.end(); iter++)
//        cout << *iter << ' ';
//}