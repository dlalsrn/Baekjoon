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
vector <int> temp;
vector <int> ans;
vector <int> x;
vector <NODE> query;
int sqrtN, N, M, l, r, cnt = 0;

bool compare(NODE a, NODE b)
{
	if (a.START / sqrtN != b.START / sqrtN)
		return a.START / sqrtN < b.START / sqrtN;
	else
		return a.END < b.END;
}

void sub(int i)
{
	if (!(--counting[value[i]]))
		cnt--;
}

void add(int i)
{
	if (!(counting[value[i]]++))
		cnt++;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	sqrtN = sqrt(N);

	value = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> value[i];
		x.push_back(value[i]);
	}

	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());

	for (int i = 1; i <= N; i++)
		value[i] = lower_bound(x.begin(), x.end(), value[i]) - x.begin();
	
	counting = vector<int>(x.size(), 0);

	cin >> M;
	ans = vector<int>(M);

	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		query.push_back({ l, r, i });
	}
	sort(query.begin(), query.end(), compare);

	cnt = 0;
	for (int i = query[0].START; i <= query[0].END; i++)
		add(i);

	ans[query[0].INDEX] = cnt;
	int left = query[0].START, right = query[0].END;

	for (int i = 1; i < M; i++)
	{
		while (left < query[i].START)
			sub(left++);
		while (left > query[i].START)
			add(--left);
		while (right < query[i].END)
			add(++right);
		while (right > query[i].END)
			sub(right--);
		ans[query[i].INDEX] = cnt;
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << '\n';

	return 0;
}