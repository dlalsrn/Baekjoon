// 화려한 마을2
// 22.10.17
// 구간에서 가장 많이 나온 수의 개수를 출력하는 문제
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

int counting[200001]{};
int total_counting[100001]{};
int value[100001]{};
int ans[100001]{};
//vector <int> counting;
//vector <int> total_counting; // total_counting[counting[i]] i의 개수만큼을 가진 숫자의 개수
//vector <int> value;
//vector <int> ans;
vector <NODE> query;
int sqrtN, N, M, l, r, mx;

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

	//value = vector<int>(N + 1);
	//counting = vector<int>(200001, 0);
	//total_counting = vector<int>(100001, 0);
	//ans = vector<int>(M);

	for (int i = 1; i <= N; i++)
		cin >> value[i];

	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		query.push_back({ l, r, i });
	}
	sort(query.begin(), query.end(), compare);

	mx = 0;
	for (int i = query[0].START; i <= query[0].END; i++)
	{
		counting[100000 + value[i]]++;
		if (!total_counting[counting[100000 + value[i]]])
			mx++;
		total_counting[counting[100000 + value[i]]]++;
	}
	ans[query[0].INDEX] = mx;

	int left = query[0].START, right = query[0].END;
	for (int i = 1; i < M; i++)
	{
		while (left < query[i].START)
		{
			total_counting[counting[100000 + value[left]]]--;
			if (!total_counting[counting[100000 + value[left]]])
				mx--;
			counting[100000 + value[left]]--;
			left++;
		}
		while (left > query[i].START)
		{
			left--;
			counting[100000 + value[left]]++;
			if (!total_counting[counting[100000 + value[left]]])
				mx++;
			total_counting[counting[100000 + value[left]]]++;
		}
		while (right < query[i].END)
		{
			right++;
			counting[100000 + value[right]]++;
			if (!total_counting[counting[100000 + value[right]]])
				mx++;
			total_counting[counting[100000 + value[right]]]++;
		}
		while (right > query[i].END)
		{
			total_counting[counting[100000 + value[right]]]--;
			if (!total_counting[counting[100000 + value[right]]])
				mx--;
			counting[100000 + value[right]]--;
			right--;
		}
		ans[query[i].INDEX] = mx;
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << '\n';

	return 0;
}