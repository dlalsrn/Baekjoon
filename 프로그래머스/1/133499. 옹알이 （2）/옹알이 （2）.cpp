#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    vector<string> use = {"aya", "ye", "woo", "ma"};

    for (int i = 0; i < babbling.size(); i++)
    {
        string str = babbling[i];
        int index = 0;
        int prevIndex = -1;
        string prevStr = "";

        while (index != str.size())
        { 
            prevIndex = index;

            for (int j = 0; j < use.size(); j++)
            {
                string sub = str.substr(index, use[j].size());
                if ((sub == use[j]) && (sub != prevStr))
                {
                    prevStr = use[j];
                    index += use[j].size();
                    break;
                }
            }

            if (index == prevIndex) // 문장을 읽지 못함
            {
                break;
            }
        }
        
        if (index == str.size())
        {
            cout << str << '\n';
            answer++;
        }
    }

    return answer;
}