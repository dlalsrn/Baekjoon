#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector <int> v;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return 0;
}