#include <bits/stdc++.h>
using namespace std;

int N, a, b, sum = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (a == 136) sum += 1000;
		else if (a == 142) sum += 5000;
		else if (a == 148) sum += 10000;
		else sum += 50000;
	}

	cout << sum;
}