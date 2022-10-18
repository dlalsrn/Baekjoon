#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int H, W, total = 0, l_max, r_max;
	cin >> H >> W;
	vector <int> block(W);
	
	for (int i = 0; i < W; i++)
		cin >> block[i];

	for (int i = 0; i < W; i++)
	{
		l_max = 0;
		r_max = 0;
		for (int j = i - 1; j >= 0; j--)
			if (block[j] > l_max)
				l_max = block[j];
		for (int j = i + 1; j < W; j++)
			if (block[j] > r_max)
				r_max = block[j];
		if (l_max > r_max)
			swap(l_max, r_max);
		if (l_max > block[i])
			total += l_max - block[i];
	}
	cout << total;
	return 0;
}