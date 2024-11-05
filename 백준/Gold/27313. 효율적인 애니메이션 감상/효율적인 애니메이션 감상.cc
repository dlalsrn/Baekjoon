#include <bits/stdc++.h>
using namespace std;

int N, M, K, t, ans = 0;
vector <int> v;
priority_queue <int, vector<int>, greater<>> pq;

int main() 
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t <= M) v.push_back(t);
    }

    sort(v.begin(), v.end());

    if (v.size()) {
        pq.push(v[0]);
        ans++;
        for (int i = 1; i < v.size(); i++) {
            if (pq.size() == K) {
                if (pq.top() + v[i] > M) {
                    break;
                }
                else {
                    pq.push(pq.top() + v[i]);
                    pq.pop();
                }
            }
            else {
                pq.push(v[i]);
            }
            ans++;
        }
    }

    cout << ans;

    return 0;
}
