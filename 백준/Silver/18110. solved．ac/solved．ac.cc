#include <bits/stdc++.h>
using namespace std;

double N;
int x, sum = 0;
vector <int> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	if (N == 0) {
		cout << 0;
		return 0;
	}

	v = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	double d = N * 0.15;
	int t = (int)round(d);
	for (int i = t; i < N - t; i++) {
		sum += v[i];
	}

	cout << (int)round((double)sum / (N - t * 2));

	return 0;
}