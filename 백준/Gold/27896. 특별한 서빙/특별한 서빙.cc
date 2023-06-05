#include <iostream>
#include <queue>
using namespace std;

long long n, m, y;
long long tmp = 0, egg = 0;
queue<int> q;               //급식 순서
priority_queue<int> pq;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> y;
        q.push(y);
    }

    while (!q.empty()) {
        pq.push(q.front());     //급식 배식 시작
        tmp += q.front(); // 불만도 더하기

        if (tmp >= m) {  //가지 배식
            egg++;
            tmp -= pq.top() * 2;
            pq.pop();
        }

        q.pop();                //급식 배식 완료
    }
    cout << egg;
    return 0;
}