//
// Created by 이유정 on 2023/01/02.
//

/*
 * 예제 3-1 거스름돈
 * 카운터에 거스름돈으로 사용할 500원, 100원, 50원, 10원짜리 동전이 "무한히 존재"한다고 가정한다.
 * 손님에게 거슬러줘야할 돈이 N원 일 때, 거슬러줘야할 동전의 "최소 갯수"를 구하여라.
 * 단, 거슬러 줘야할 돈 N은 항상 10의 배수이다. -> 지불 불가능한 거스름돈 존재 x
 */


#include <iostream>

using namespace std;

int coins[4] = {500, 100, 50, 10};


int main() {

    int n;
    cin >> n;

    int ans = 0;

    //시간 복잡도 : O(화폐의 가짓수) -> 최대 4번 작동함
    for(int idx=0; idx<4; idx++){
        ans += n/coins[idx];
        n = n%coins[idx];
        idx++;
    }


    cout << ans;


}
