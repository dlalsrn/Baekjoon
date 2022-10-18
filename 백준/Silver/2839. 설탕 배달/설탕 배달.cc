#include <iostream>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	if (N == 4 || N == 7)
		cout << -1;
	else
	{
		if (N % 5 == 0)
			cout << N / 5;
		else if (N % 5 == 1 || N % 5 == 3)
			cout << N / 5 + 1;
		else if (N % 5 == 2 || N % 5 == 4)
			cout << N / 5 + 2;
	}
	return 0;
}