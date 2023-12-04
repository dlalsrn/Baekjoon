#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		transform(x.begin(), x.end(), x.begin(), ::tolower);

		cout << x << '\n';
	}

	return 0;
}