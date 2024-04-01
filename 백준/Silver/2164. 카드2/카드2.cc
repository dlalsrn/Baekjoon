#include <bits/stdc++.h>
using namespace std;

int N;
queue <int> q;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++) q.push(i);

    while (q.size() != 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();

    return 0;
}