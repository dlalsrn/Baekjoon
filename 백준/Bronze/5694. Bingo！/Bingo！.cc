#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B;
bool TF;
vector<int> v;
vector<bool> check;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1)
    {
        cin >> N >> B;
        if (N == 0 && B == 0)
            break;

        v = vector<int>(B);
        check = vector<bool>(N + 1, false);

        for (int i = 0; i < B; i++)
            cin >> v[i];
        
        sort(v.begin(), v.end());

        for (int i = 0; i < B; i++)
            for (int j = i + 1; j < B; j++)
                check[abs(v[i] - v[j])] = true;

        TF = true;

        for (int i = 1; i <= N; i++)
        {
            if (!check[i])
            {
                TF = false;
                break;
            }
        }

        cout << (TF ? 'Y' : 'N') << '\n';
    }
    return 0;
}