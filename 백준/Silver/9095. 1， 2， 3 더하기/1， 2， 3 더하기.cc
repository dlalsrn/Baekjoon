#include <iostream>
#include <memory.h>
using namespace std;

int main(void)
{
	int N, num;
	int ary[12];
	cin >> N;
	for (int j = 0; j < N; j++)
	{
		memset(ary, 0, 4*12);
		cin >> num;
		ary[1] = 1;
		ary[2] = 1;
		ary[3] = 1;
		for (int i = 1; i < num; i++)
		{
			if (i + 1 < num + 1)
				ary[i + 1] += ary[i];
			if (i + 2 < num + 1)
				ary[i + 2] += ary[i];
			if (i + 3 < num + 1)
				ary[i + 3] += ary[i];
		}
		cout << ary[num] << '\n';
	}
	
	return 0;
}