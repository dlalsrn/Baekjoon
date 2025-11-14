// 디스크 컨트롤러
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
using ti3 = tuple<int, int, int>;

int solution(vector<vector<int>> jobs)
{
	int answer = 0;

	priority_queue<ti3, vector<ti3>, greater<ti3>> dc;

	sort(jobs.begin(), jobs.end());

	ti3 curJob = make_tuple(jobs[0][1], jobs[0][0], 0); // 작업 시간, 시작 시간, index
	int curTime = jobs[0][0];
	int workIndex = 1;

	while (workIndex < jobs.size())
	{
		if (curTime + get<0>(curJob) < jobs[workIndex][0]) // 현재 작업이 다음 작업의 시작 시간 전에 끝난다면
		{
			answer += (curTime + get<0>(curJob)) - get<1>(curJob);
			curTime += get<0>(curJob);

			if (dc.empty())
			{
				curJob = make_tuple(jobs[workIndex][1], jobs[workIndex][0], workIndex);
				curTime = jobs[workIndex][0];
				workIndex++;
			}
			else
			{
				curJob = dc.top();
				dc.pop();
			}
		}
		else
		{
			dc.push(make_tuple(jobs[workIndex][1], jobs[workIndex][0], workIndex));
			workIndex++;
		}
	}

	answer += (curTime + get<0>(curJob)) - get<1>(curJob);
	curTime += get<0>(curJob);

	while (!dc.empty())
	{
		curJob = dc.top();
		dc.pop();

		answer += (curTime + get<0>(curJob)) - get<1>(curJob);
		curTime += get<0>(curJob);
	}

	return answer / jobs.size();
}