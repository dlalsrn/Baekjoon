#include <iostream>
#include <vector>
using namespace std;

int N, M, x, cnt = 0;
vector <int> a;
vector <int> b;
vector <int> c;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (!a[i])
			b.push_back(x);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> x;
		c.push_back(x);
	}

	for (int i = b.size() - 1; i >= 0 && cnt != M; i--)
	{
		cnt++;
		cout << b[i] << ' ';
	}

	for (int i = 0; i < c.size() && cnt != M; i++)
	{
		cnt++;
		cout << c[i] << ' ';
	}

	return 0;
}