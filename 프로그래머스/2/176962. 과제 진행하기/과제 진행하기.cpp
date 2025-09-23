// 과제 진행하기
#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int transMinute(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    vector<tuple<int, int, string>> v;
    stack<pair<string, int>> st;
    int curTime = 0;

    for (int i = 0; i < plans.size(); i++)
    {
        string name = plans[i][0];
        int start = transMinute(plans[i][1]);
        int work = stoi(plans[i][2]);
        v.push_back(make_tuple(start, work, name));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        auto [start, work, name] = v[i];

        while (!st.empty() && curTime + st.top().second <= start)
        {
            answer.push_back(st.top().first);
            curTime += st.top().second;
            st.pop();
        }

        
        if (st.empty())
        {
            curTime = start;
            st.push(make_pair(name, work));
        }
        else
        {
            auto& [workName, remainTime] = st.top();
            remainTime -= start - curTime;

            curTime = start;
            st.push(make_pair(name, work));
        }
    }

    while (!st.empty())
    {
        answer.push_back(st.top().first);
        st.pop();
    }

    return answer;
}