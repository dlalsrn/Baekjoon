#include <bits/stdc++.h>
using namespace std;

int s, m, l, score;

int main(void)
{
    cin >> s >> m >> l;
    score = 1 * s + 2 * m + 3 * l;

    if (score >= 10) cout << "happy";
    else cout << "sad";

	return 0;
}