// 세 용액
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll abc(ll a)
{
	if (a < 0) 
		return a * (-1);
	else 
		return a;
}

int main(void)
{
	int N, i, j, k, min_i, min_j, min_k;
	ll num, min = 4000000000;
	vector <ll> v;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		scanf(" %lld", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (i = 0; i < N - 2; i++)
	{
		j = i + 1;
		k = N - 1;
		while (j < k)
		{
			ll s = v[i] + v[j] + v[k];
			if (abc(s) < min)
			{
				min = abc(s);
				min_i = i;
				min_j = j;
				min_k = k;
				if (min == 0)
					break;
			}
			if (s < 0)
				j++;
			else
				k--;
		}
		if (min == 0)
			break;
	}
	
	printf("%lld %lld %lld\n", v[min_i], v[min_j], v[min_k]);
	return 0;
}