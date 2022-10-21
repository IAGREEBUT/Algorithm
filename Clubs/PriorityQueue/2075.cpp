//
// 2075 - N번째로 큰 수
// 크기가 N인 min heap에서 제일 작은  (크기 제한이 있기때문)
//

#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, num;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> pq; //greater(작은 것부터)

    for (int i = 0; i < n * n; i++) {
        cin >> num;

        if(i<n) pq.push(num);
        else if( num > pq.top() ){
            pq.pop();
            pq.push(num);
        }
    }

    cout << pq.top();

}

