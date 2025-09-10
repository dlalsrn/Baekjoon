#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int calTime(string min, string sec)
{
    int minute = stoi(min) * 60;
    int second = stoi(sec);
    return minute + second;
}

int solution(vector<vector<string>> book_time)
{
    int answer = 0;
    int cnt = 0;
    priority_queue<pi, vector<pi>, greater<pi>> inTime;
    priority_queue<pi, vector<pi>, greater<pi>> outTime;

    for (int i = 0; i < book_time.size(); i++)
    {
        int in = calTime(book_time[i][0].substr(0, 2), book_time[i][0].substr(3, 2));
        int out = calTime(book_time[i][1].substr(0, 2), book_time[i][1].substr(3, 2));
        inTime.push(make_pair(in, out + 10));
    }

    while (!inTime.empty())
    {
        auto [in, out] = inTime.top();
        inTime.pop();

        while (!outTime.empty() && outTime.top().first <= in)
        {
            outTime.pop();
            cnt--;
        }

        outTime.push(make_pair(out, in));
        cnt++;

        answer = max(answer, cnt);
    }

    return answer;
}