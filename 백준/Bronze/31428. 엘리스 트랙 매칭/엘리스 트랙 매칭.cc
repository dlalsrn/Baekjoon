#include <bits/stdc++.h>
using namespace std;

int N, C = 0, S = 0, I = 0, A = 0;
char x, t;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 'C') C++;
		if (x == 'S') S++;
		if (x == 'I') I++;
		if (x == 'A') A++;
	}

	cin >> t;

	if (t == 'C') cout << C;
	if (t == 'S') cout << S;
	if (t == 'I') cout << I;
	if (t == 'A') cout << A;
}