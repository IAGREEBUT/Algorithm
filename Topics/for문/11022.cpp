/*
 * 백준 - 단계별 문제풀이 : for문
 * 11022번
 *
 * A+B - 8
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    int a, b, n;
    cin >> n;

    vector<pair<int, int>> list;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        list.push_back({a, b});
        res.push_back(a + b);
    }

    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": " << list[i].first << " + " << list[i].second << " = " << res[i] << "\n";
    }

}


//#include <iostream>
//
//int main(){
//
//    //속도빠르게하기
//    std::cin.tie(NULL);
//    std::ios_base::sync_with_stdio(false);
//
//    int T;
//    int a;
//    int b;
//
//    std::cin>>T;
//
//    for(int i=0;i<T;i++){
//
//        std::cin>>a>>b;
//        std::cout<<"Case #"<<i+1<<": "<<a<<" + "<<b<<" = "<<a+b<<"\n";
//
//    }
//
//
//}