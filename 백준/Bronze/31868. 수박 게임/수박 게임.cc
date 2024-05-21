#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i < N; i++) K /= 2;

	cout << K;

	return 0;
}