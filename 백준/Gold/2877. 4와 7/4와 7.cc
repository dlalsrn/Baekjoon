#include <iostream>
using namespace std;

int main(void)
{
	int N;
	string total = "";
	cin >> N;
	N -= 1;

	for (int i = 2; N >= 0; N -= i, i *= 2)
	{
		if (N % i < i / 2)
			total = '4' + total;
		else
			total = '7' + total;
	}

	cout << total;
	return 0;
}