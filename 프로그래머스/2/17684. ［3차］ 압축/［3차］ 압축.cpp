#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int cnt = 1;
unordered_map<string, int> um;

vector<int> solution(string msg)
{
    vector<int> answer;
    
    for (int i = 0; i < 26; ++i)
    {
        string str(1, 'A' + i);
        um[str] = cnt++;
    }
    
    int index = 0;
    while (index < msg.size())
    {
        string str(1, msg[index]);
        int t = 0;
        while (index < msg.size())
        {
            if (um.find(str) != um.end())
            {
                t = um[str];
                str += msg[++index];
            }
            else
            {
                answer.push_back(t);
                um[str] = cnt++;
                break;
            }
        }
        
        if (index >= msg.size())
        {
            answer.push_back(t);
        }
    }
    
    return answer;
}