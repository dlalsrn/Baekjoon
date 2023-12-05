#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

int N;
bitset <33554433> bs;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	bs.reset();

	while (cin >> N)
	{
		if (!bs[N])
		{
			cout << N << ' ';
			bs[N] = true;
		}
	}

	return 0;
}