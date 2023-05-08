#include <iostream>
#include <vector>
using namespace std;

vector <int> node;
int N, n;

void print(int d, int L, int T)
{
	if (d == 0)
		cout << node[L] << ' ';
	else
	{
		print(d - 1, L - ((T - L) / 2), L);
		print(d - 1, L + ((T - L) / 2), T);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N;

	node.resize((1 << N) - 1);

	for (int i = 0; i < (1 << N) - 1; i++)
		cin >> node[i];

	for (int i = 0; i < N; i++)
	{
		print(i, ((1 << N) - 1) / 2, (1 << N) - 1);
		cout << '\n';
	}

	return 0;
}