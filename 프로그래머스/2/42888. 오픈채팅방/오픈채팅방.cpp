#include <bits/stdc++.h>
using namespace std;

map<string, string> nickname; // { uid, name }

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    string cmd, uid, name;

    for (int i = 0; i < record.size(); i++)
    {
        istringstream iss(record[i]); // record[i]를 input으로 사용
        iss >> cmd >> uid;

        if (cmd == "Enter" || cmd == "Change")
        {
            iss >> name;
            nickname[uid] = name;
        }
    }

    for (int i = 0; i < record.size(); i++)
    {
        istringstream iss(record[i]); // record[i]를 input으로 사용
        iss >> cmd >> uid;

        if (cmd == "Enter") answer.push_back(nickname[uid] + "님이 들어왔습니다.");
        else if (cmd == "Leave") answer.push_back(nickname[uid] + "님이 나갔습니다.");
    }

    return answer;
}