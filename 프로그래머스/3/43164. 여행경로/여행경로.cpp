// 여행경로
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
using psb = pair<string, bool>;

vector<string> DFS(string start,
    int maxCnt,
    unordered_map<string, vector<psb>> ticket,
    vector<string> path
)
{
    if (path.size() == maxCnt)
    {
        return path;
    }

    for (auto& [next, used] : ticket[start])
    {
        if (!used)
        {
            used = true;
            path.push_back(next);

            vector<string> res = DFS(next, maxCnt, ticket, path);
            if (res.size() == maxCnt)
            {
                return res;
            }

            path.pop_back();
            used = false;
        }
    }
    
    return {};
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    vector<string> path;
    unordered_map<string, vector<psb>> ticket;
    
    for (int i = 0; i < tickets.size(); i++)
    {
        string start = tickets[i][0];
        string end = tickets[i][1];
        ticket[start].push_back(make_pair(end, false));
    }

    for (auto& it : ticket)
    {
        vector<psb>& v = it.second;
        sort(v.begin(), v.end());
    }

    path.push_back("ICN");
    answer = DFS("ICN", tickets.size() + 1, ticket, path);

    return answer;
}
