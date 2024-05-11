#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	if (N - 2 == K || N - 1 == K) cout << "C win";
	else if (N == K || N / 2 <= K) cout << "A and B win";
	else cout << "C win";

	return 0;
}
