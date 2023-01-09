//
// 13305번 - 주유소
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;


bool compare(ii a, ii b) {

    return a.first < b.first; //오름차순 (작은게 앞으로)

}


int main() {

    int n;//도시의 수

    cin >> n;

    vector<int> dist;//도시를 연결하는 도로의 길이
    dist.assign(n - 1, 0);

    for (int i = 0; i < n - 1; i++) {
        cin >> dist[i];
    }

    vector<ii> price; //각 도시 주유소의 리터당 가격 , 마을번
    price.assign(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> price[i].first;
        price[i].second = i; //마을번호
    }

    //맨 마지막 마을은 (도착지) 아무의미도 없음
    price.pop_back(); //마지막 항 제거


    sort(price.begin(), price.end(), compare);


//    for (int i = 0; i < n - 1; i++) {
//        cout << price[i].first << " " << price[i].second << "\n";
//    }


    vector<ii> p;
    p.assign(n - 1, {0, 0});

    for (int i = 0; i < n - 1; i++) {

        p[price[i].second].first = price[i].first; //가격
        p[price[i].second].second = i;


    }

//
//    for (int i = 0; i < n - 1; i++) {
//        cout << p[i].first << " " << p[i].second << "\n";
//    }


//    int ans = price[0] * dist[0]; // 최초의 시작에서는 다음 도시까지 갈 기름이 꼭 필요하다 (강제)


    long long ans = 0;
    int pr = p[0].first; // 첫마을의 기름값
    int rank = p[0].second; //지금마을의 순위(가격이 싼 순위)


    for (int i = 0; i < n - 1; i++) { // 맨 마지막 도시의 기름값은 상관없음

        if (p[i].second < rank) {
            pr = p[i].first;
            rank = p[i].second;
        }

        ans += (long long)pr * dist[i]; //지금 기름값 * 다음 도시까지의 거리
//        cout << pr << "*" << dist[i] << " = " << pr * dist[i] << "\n";

    }

    cout << ans;

}