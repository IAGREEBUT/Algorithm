//
// Created by 이유정 on 2023/01/10.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    long t, cur = 2e9, sum = 0; // t: 마을의 수 / cur : 방문한 마을 중 기름 값이 가장 싼 마을의 기름 값

    cin >> t;

    vector<int> oil(t, 0);
    vector<int> dist(t - 1, 0);

    for (int i = 0; i < t - 1; i++)
        cin >> dist[i];

    for (int i = 0; i < t; i++)
        cin >> oil[i];

    for (int i = 0; i < t - 1; i++) {
        if (oil[i] < cur)cur = oil[i]; //현재 방문 마을의 기름값이 더 싸면 낼 가격을 갱신한다
        sum += cur * dist[i];//
    }

    cout << sum;
}