#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    unordered_map<string, unordered_set<string>> reporting; // 신고한 목록
    unordered_map<string, unordered_set<string>> reported; // 신고당한 목록

    for (int i = 0; i < report.size(); i++)
    {
        istringstream iss(report[i]);
        string userId, reportId;
        iss >> userId >> reportId;

        reporting[userId].insert(reportId); // userId가 reportId를 신고 함
        reported[reportId].insert(userId); // reportId가 userId한테 신고 당함
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        int cnt = 0;
        string userId = id_list[i];
        
        for (const string& reportId : reporting[userId])
            if (reported[reportId].size() >= k) cnt++;

        answer.push_back(cnt);
    }

    return answer;
}