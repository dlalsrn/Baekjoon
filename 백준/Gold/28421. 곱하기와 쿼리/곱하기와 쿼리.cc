#include <iostream>
#include <vector>
using namespace std;

int N, Q, ch, x;
bool TF;
vector <int> v;
vector <int> exist(10001, 0);

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> Q;

	v = vector<int>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		exist[v[i]]++;
	}

	for (int i = 0; i < Q; i++)
	{
		cin >> ch >> x;
		TF = false;

		if (ch == 2)
		{
			if (v[x - 1] == 0)
				continue;
			exist[v[x - 1]]--;
			v[x - 1] = 0;
			exist[0]++;
		}
		else
		{
			if (x == 0 && exist[0] && N != 1)
			{
				cout << 1 << '\n';
				continue;
			}
			for (int j = 1; j <= 10000; j++)
			{
				if (x / j > 10000)
					continue;
				if (x % j || !(exist[j] && exist[x / j]) || (j == (x / j) && exist[j] == 1))
					continue;
				TF = true;
				break;
			}

			cout << (TF ? 1 : 0) << '\n';
		}
	}
}