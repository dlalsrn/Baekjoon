#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char x = s[s.size() - 1];
        s.pop_back();
        s = x + s;

        st = stack<char>();
        bool check = true;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '(' || s[j] == '{' || s[j] == '[') st.push(s[j]);
            else
            {
                if (s[j] == ')')
                {
                    if (!st.empty() && st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }
                else if (s[j] == '}')
                {
                    if (!st.empty() && st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }
                else
                {
                    if (!st.empty() && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }
            }
        }

        if (st.empty() && check) answer++;
    }

    return answer;
}
