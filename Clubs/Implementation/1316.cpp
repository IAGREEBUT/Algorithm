// <구현, 문자열>
// 1316 - 그룹단어 체커
// 실버 5

/*
 * 아이디어 1
 * set에 중복값이 허용되지 않는다는 점을 이용
 * 한글자씩 이전 글자와 비교
 * 같은경우 - 상관x
 * 다른경우 - 이미 set내부에 존재하면 중복단어가 아님
 *
 * -> find라는 함수를 사용해서 효율이 좋지 않음
 *
 * 아이디어 2
 * bool배열 을 알파벳26개만큼 만들어서 사용여부를 체크한다
 * TIP 'b' - 'a' = 1
 *
 *
 */

#include <iostream>
#include <set>

using namespace std;

int main() {


    int n, ans = 0;
    string str;
    cin >> n;

    while (n--) {

        cin >> str;


        set<char> s;
        char past = str.at(0);
        s.insert(past);

        bool flag = true;
        for (int i = 1; i < str.length(); i++) {

            if (past != str.at(i)) {
                if (s.find(str.at(i)) != s.end()) {// -> find는 오래걸림
                    flag = false;
                    break;
                }
                s.insert(str.at(i));
                past = str.at(i); //갱신재
            }


        }

        if (flag) ans++;
    }

    cout << ans;

}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isGroup(string str) {
//    char cur = '.'; //현재의 문자
//    vector<bool> alphabet(26, false); //각 알파벳의 등장 여부를 체크
//
//    for (int i = 0; i < str.size(); i++) {
//        if (str[i] == cur) //연속해서 나타난 문자
//            continue;
//        //이전의 문자와 다른 문자가 나타났을 때
//        if (alphabet[str[i] - 'a']) //이전에 등장했던 문자면 떨어져서 나타난 것
//            return false;
//        cur = str[i]; //현재의 문자 갱신
//        alphabet[str[i] - 'a'] = true; //등장 체크
//    }
//    return true;
//}
//
//int main() {
//    int n, result = 0;
//
//    //입력
//    cin >> n;
//    while (n--) {
//        string word;
//        cin >> word;
//
//        //연산
//        if (isGroup(word)) //그룹 단어인지 확인
//            result++;
//    }
//
//    //출력
//    cout << result;
//}