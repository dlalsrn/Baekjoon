#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef struct
{
	int START;
	int END;
	int INDEX;
}NODE;

vector <ll> counting;
vector <ll> value;
vector <ll> ans;
vector <NODE> query;
int sqrtN, N, M, l, r;
ll sum;


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
	cin >> N >> M;
	sqrtN = sqrt(N);

	value = vector<ll>(N + 1);
	counting = vector<ll>(1000001, 0);
	ans = vector<ll>(M);

	for (int i = 1; i <= N; i++)
		cin >> value[i];

	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		query.push_back({ l, r, i });
	}
	sort(query.begin(), query.end(), compare);

	sum = 0;
	for (int i = query[0].START; i <= query[0].END; i++)
	{
		counting[value[i]]++;
		sum += value[i] * (2 * counting[value[i]] - 1);
	}
	ans[query[0].INDEX] = sum;
	int left = query[0].START, right = query[0].END;

	for (int i = 1; i < M; i++)
	{
		while (left < query[i].START)
		{
			sum += value[left] * (1 - 2 * counting[value[left]]);
			counting[value[left]]--;
			left++;
		}
		while (left > query[i].START)
		{
			left--;
			counting[value[left]]++;
			sum += value[left] * (2 * counting[value[left]] - 1);
		}
		while (right < query[i].END)
		{
			right++;
			counting[value[right]]++;
			sum += value[right] * (2 * counting[value[right]] - 1);
		}
		while (right > query[i].END)
		{
			sum += value[right] * (1 - 2 * counting[value[right]]);
			counting[value[right]]--;
			right--;
		}
		ans[query[i].INDEX] = sum;
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << '\n';

	return 0;
}