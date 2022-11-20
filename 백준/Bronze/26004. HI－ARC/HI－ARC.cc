#include <iostream>
#include <algorithm>
using namespace std;

string x;
int N, H, I, A, R, C;

int main(void)
{
	cin >> N >> x;

	for (int i = 0; i < N; i++)
	{
		if (x[i] == 'H')
			H++;
		else if (x[i] == 'I')
			I++;
		else if (x[i] == 'A')
			A++;
		else if (x[i] == 'R')
			R++;
		else if (x[i] == 'C')
			C++;
	}

	cout << min({ H, I, A, R, C });
	return 0;
}