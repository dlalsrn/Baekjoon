#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

set<vector<string>> TotalSet;
unordered_map<string, bool> AlreadyBanned;
vector<string> BannedAry;

bool CheckMatch(string a, string b)
{
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); ++i)
    {
        if (b[i] == '*') continue;
        else if (a[i] != b[i]) return false;
    }

    return true;
}

void BackTrack(vector<string>& user_id, vector<string>& banned_id, int CurBannedNum)
{
    if (CurBannedNum == banned_id.size())
    {
        vector<string> temp(BannedAry);
        sort(temp.begin(), temp.end());
        TotalSet.insert(temp);

        return;
    }

    for (int i = 0; i < user_id.size(); ++i)
    {
        if (AlreadyBanned[user_id[i]]) continue;

        if (CheckMatch(user_id[i], banned_id[CurBannedNum]))
        {
            AlreadyBanned[user_id[i]] = true;
            BannedAry.push_back(user_id[i]);
            BackTrack(user_id, banned_id, CurBannedNum + 1);
            BannedAry.pop_back();
            AlreadyBanned[user_id[i]] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    BackTrack(user_id, banned_id, 0);

    return TotalSet.size();
}