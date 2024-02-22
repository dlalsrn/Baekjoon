#include <bits/stdc++.h>
using namespace std;

int N, M, K;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N >> M >> K;

	cout << min(M, K) + min(N - M, N - K);

	return 0;
}