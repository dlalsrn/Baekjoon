#include <iostream>
using namespace std;

int T, N;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;

		cout << "Case #" << t + 1 << ": ";
		if (N <= 25)
			cout << "World Finals\n";
		else if (N <= 1000)
			cout << "Round 3\n";
		else if (N <= 4500)
			cout << "Round 2\n";
		else
			cout << "Round 1\n";
	}

	return 0;
}