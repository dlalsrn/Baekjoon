#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, sum = 1, mx;
vector <int> v;

int GCD(int a, int b)
{
	int t;
	while (b)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	v = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (GCD(i, j) == 1)
			{
				v[j]++;
				sum++;
			}
		}
	}
	v[1]++;

	mx = N;
	while (mx != 1)
	{
		v[mx]--;
		cout << mx << ' ';
		if (mx + 2 <= N && v[mx + 2])
			mx += 2;
		else if (mx + 1 <= N && v[mx + 1])
			mx += 1;
		else if (mx - 1 >= 1 && v[mx - 1])
			mx -= 1;
		else
			mx -= 2;
	}
	cout << 1;
	return 0;
}