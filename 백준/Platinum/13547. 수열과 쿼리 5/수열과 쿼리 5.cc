#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct
{
	int START;
	int END;
	int INDEX;
}NODE;
vector <int> counting;
vector <int> value;
vector <int> ans;
vector <NODE> query;
int sqrtN, N, M, l, r, cnt= 0, sum;

bool compare(NODE a, NODE b)
{
	if (a.START / sqrtN != b.START / sqrtN)
		return a.START / sqrtN < b.START / sqrtN;
	else
		return a.END < b.END;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	sqrtN = sqrt(N);

	value = vector<int>(N + 1);
	counting = vector<int>(1000001, 0);

	for (int i = 1; i <= N; i++)
		cin >> value[i];

	cin >> M;
	ans = vector<int>(M + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		query.push_back({ l, r, i + 1 });
	}
	sort(query.begin(), query.end(), compare);

	cnt = 0;
	for (int i = query[0].START; i <= query[0].END; i++)
	{
		if (!counting[value[i]])
			cnt++;
		counting[value[i]]++;
	}
	ans[query[0].INDEX] = cnt;
	int left = query[0].START, right = query[0].END;

	for (int i = 1; i < M; i++)
	{
		while (left < query[i].START)
		{
			counting[value[left]]--;
			if (!counting[value[left]])
				cnt--;
			left++;
		}
		while (left > query[i].START)
		{
			left--;
			if (!counting[value[left]])
				cnt++;
			counting[value[left]]++;
		}
		while (right < query[i].END)
		{
			right++;
			if (!counting[value[right]])
				cnt++;
			counting[value[right]]++;
		}
		while (right > query[i].END)
		{
			counting[value[right]]--;
			if (!counting[value[right]])
				cnt--;
			right--;
		}
		ans[query[i].INDEX] = cnt;
	}

	for (int i = 1; i <= M; i++)
		cout << ans[i] << '\n';

	return 0;
}