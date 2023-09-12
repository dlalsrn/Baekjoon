#include <iostream>
#include <vector>
using namespace std;

int N, Q, x;
vector <bool> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> Q;

	v = vector<bool>(N + 1, false);

	for (int i = 0; i < Q; i++)
	{
		bool TF = false;
		int first = 0;
		int ori;
		cin >> x;

		ori = x;
		while (x != 1)
		{
			if (v[x])
			{
				TF = true;
				first = x;
			}
			x /= 2;
		}

		if (TF)
			cout << first << '\n';
		else
		{
			v[ori] = true;
			cout << 0 << '\n';
		}
	}

	return 0;
}