#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, num;
	cin >> N;
	vector <int> total(N);
	vector <int> people(N);
	vector <int> cnt(N);
	for (int i = 0; i < N; i++)
		cin >> people[i];
	for (int i = 0; i < N; i++)
		cin >> cnt[i];
	sort(people.begin(), people.end());

	for (int i = N - 1; i >= 0; i--)
	{
		int h = lower_bound(people.begin(), people.end(), people[cnt[i]]) - people.begin();
		total[i] = people[h];
		people.erase(people.begin() + h);
	}
	for (int i = 0; i < N; i++)
		cout << total[i] << '\n';
	return 0;
}