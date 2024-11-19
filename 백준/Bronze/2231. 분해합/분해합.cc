#include <bits/stdc++.h>
using namespace std;

int N;

bool isEqual(int i)
{
	int sum = i;

	while (i) {
		sum += i % 10;
		i /= 10;
	}

	return (sum == N ? true : false);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	int i = 1;
	while (i <= 1'000'000 && !isEqual(i)) {
		i++;
	}
	
	cout << (i == 1'000'001 ? 0 : i);

	return 0;
}