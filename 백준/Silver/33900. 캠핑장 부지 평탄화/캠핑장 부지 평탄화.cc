#include <bits/stdc++.h>
using namespace std;

int N, M, R, C;
int ans = 0;

vector<vector<int>> mount, work;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> N >> M >> R >> C;

    mount = vector<vector<int>>(N, vector<int>(M));
    work = vector<vector<int>>(R, vector<int>(C));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mount[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> work[i][j];
        }
    }

    for (int i = 0; i < N - R + 1; i++)
    {
        for (int j = 0; j < M - C + 1; j++)
        {
            bool check = true;
            int dig = mount[i][j] - work[0][0];

            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {
                    if (mount[i + r][j + c] - work[r][c] != dig)
                    {
                        check = false;
                    }
                }
            }

            if (check)
            {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}