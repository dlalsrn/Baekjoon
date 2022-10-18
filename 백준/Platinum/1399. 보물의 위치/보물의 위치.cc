#include <iostream>
#include <vector>
using namespace std;

int dig(int n)
{
	while (n >= 10)
	{
		int sum = n;
		n = 0;
		while (sum)
		{
			n += sum % 10;
			sum /= 10;
		}
	}
	return n;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, K, M, X, Y, distance, point;
	bool TF;
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector <pair<int, int>> v;
		cin >> K >> M;
		X = 0;
		Y = 0;
		TF = false;
		point = 0;
		distance = 1;
		for (int j = 0; j < K; j++)
		{
			X += dx[j % 4] * distance;
			Y += dy[j % 4] * distance;
			for (int k = 0; k < v.size(); k++)
			{
				if (v[k] == pair<int, int> {X, Y})
				{
					point = k;
					TF = true;
					break;
				}
			}
			if (TF)
				break;
			v.push_back({ X, Y });
			distance *= M;
			distance = dig(distance);
		}
		if (TF)
		{
			K -= (point + 1);
			X = v[point + (K % (v.size() - point))].first;
			Y = v[point + (K % (v.size() - point))].second;
		}
		cout << X << ' ' << Y << '\n';
	}
	return 0;
}