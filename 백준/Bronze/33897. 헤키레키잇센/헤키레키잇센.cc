#include <bits/stdc++.h>
using namespace std;

int N;
int use = 0, cnt = 0;
int mx = 0;
vector<int> v;


int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int prev = -1;
    for (int i = 0; i < N; i++)
    {
        if (v[i] >= prev)
        {
            cnt++;
        }
        else
        {
            mx = max(mx, cnt);
            cnt = 1;
            use++;
        }

        if (i == N - 1)
        {
            mx = max(mx, cnt);
            use++;
        }
        
        prev = v[i];
    }

    cout << use << ' ' << mx << '\n';

    return 0;
}