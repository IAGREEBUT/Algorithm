/*
 * 백준 - 단계별 문제풀이 : for문
 * 10871번
 *
 * X보다 작은 수
 * 정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v;
    int n, x, input;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input < x) v.push_back(input);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


}



//#include <iostream>
//
//int main(){
//
//    int N;
//    int X;
//
//    std::cin>>N>>X;
//
//    int *array = new int[N];
//
//    for(int i=0;i<N;i++){
//        int num;
//        std::cin>>num;
//        array[i]=num;
//    }
//
//    for(int i=0;i<N;i++){
//
//        if(array[i]<X) std::cout<<array[i]<<" ";
//    }
//
//}