#include <string>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
using pi = pair<int, int>;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    stack<pi> st;

    for (int i = 0; i < numbers.size(); i++)
    {
        while (!st.empty() && st.top().first < numbers[i])
        {
            auto [_, index] = st.top();
            answer[index] = numbers[i];
            st.pop();
        }

        st.push(make_pair(numbers[i], i));
    }

    return answer;
}