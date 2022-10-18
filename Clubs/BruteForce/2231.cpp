#include <iostream>

using namespace std;

/*
 * 2231번 분해합
 * 1< n < 1,000,000 이므로
 * 최대값 1,000,000으로 고려해도 -> 분해합 구하기 최대 7번 연산
 * 1000000 * 7 < 1억 이하이므로 브루트 포스 가능
 *
 *
 */

int solution(int n){


    for(int i=0; i<n; i++){ //자신이 자신의 분해합이 될수는 없다

        int sum = i;

        int tmp = i;
        while(tmp>0){
            sum+= tmp%10; //일의 자리수 더하기
            tmp /= 10;//일의 자리수 버리기
        }

        if(sum==n) return i;
    }

    return 0; //없음

}


int main(){

    int n;
    cin>>n;

    cout<<solution(n);



}