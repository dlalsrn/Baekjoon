// 110 옮기기
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> s)
{
    vector<string> answer;

    for (string& str : s)
    {
        int one = 0;
        int ooz = 0;
        string ans = "";

        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '1')
            {
                ++one;
            }
            else
            {
                if (one < 2)
                {
                    for (int j = 0; j < one; ++j)
                    {
                        ans.push_back('1');
                    }
                    ans.push_back('0');
                    one = 0;
                }
                else
                {
                    one -= 2;
                    ++ooz;
                }
            }
        }

        for (int i = 0; i < ooz; ++i)
        {
            ans.append("110");
        }

        for (int i = 0; i < one; ++i)
        {
            ans.push_back('1');
        }

        answer.push_back(ans);
    }

    return answer;
}
