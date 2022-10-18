#include <iostream>
using namespace std;

int main(void)
{
	int n, k;
	double min, max, T;
	int ary[100000];
	bool check = false;
	cin >> n;
	ary[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> ary[i];
		T = (double)ary[i] / i;
		if (i == 1)
		{
			max = T;
			min = T;
		}
		else
		{
			if (T > max)
				max = T;
			else if (T < min)
				min = T;
		}
	}
	cin >> k;

	if (k <= max && k >= min)
		cout << "T";
	else
		cout << "F";

	return 0;
}