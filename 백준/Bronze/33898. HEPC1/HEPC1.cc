#include <bits/stdc++.h>
using namespace std;

string hepc1, hepc2;
string a, b;
vector<string> ans = { "HEPC", "EPCH", "PCHE", "CHEP", "CPEH", "PEHC", "EHCP", "HCPE" };

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> a >> b;

    bool check = false;
    hepc1 = a + b[1] + b[0];
    hepc2 = b + a[1] + a[0];

    for (string x : ans)
    {
        if (x == hepc1 || x == hepc2)
        {
            check = true;
            break;
        }
    }

    cout << (check ? "YES" : "NO");

    return 0;
}