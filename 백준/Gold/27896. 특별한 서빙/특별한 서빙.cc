#include <iostream>
#include <queue>
using namespace std;

long long N, M, Y, x, cnt = 0, sum = 0;
priority_queue<int> pq;

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        cin >> x;
        pq.push(x);
        sum += x;

        if (sum >= M) {
            cnt++;
            sum -= pq.top() * 2;
            pq.pop();
        }
    }

    cout << cnt;

    return 0;
}