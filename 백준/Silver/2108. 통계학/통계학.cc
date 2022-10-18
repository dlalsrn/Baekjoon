#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int N, num, max_fre = 0;
	int ary[8001] = { 0 };
	int sum = 0;
	vector <int> v;
	vector <int> search;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		ary[4000 + num]++;
		if (ary[4000 + num] > max_fre)
			max_fre = ary[4000 + num];
		sum += num;
		v.push_back(num);
	}
	for (int i = 0; i < 4001; i++)
	{
		if (i == 0)
		{
			if (ary[4000] == max_fre)
				search.push_back(i);
		}
		else
		{
			if (ary[4000 + i] == max_fre)
				search.push_back(i);
			if (ary[4000 - i] == max_fre)
				search.push_back(-i);
		}
	}

	sort(search.begin(), search.end());
	sort(v.begin(), v.end());

	if (search.size() == 1)
		num = search[0];
	else
		num = search[1];

	double avg = round((double)sum / N);
	if (avg == 0)
		avg = 0;
	printf("%.0lf\n", avg);
	printf("%d\n", v[v.size() / 2]);
	printf("%d\n", num);
	printf("%d\n", v.back() - v.front());
	return 0;
}