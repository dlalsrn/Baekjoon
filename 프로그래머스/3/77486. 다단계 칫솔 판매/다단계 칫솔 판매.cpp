// 다단계 칫솔 판매
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> sum;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    parent = unordered_map<string, string>();
    sum = unordered_map<string, int>();

    for (int i = 0; i < enroll.size(); ++i)
    {
        parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++)
    {
        string name = seller[i];
        int price = amount[i] * 100;

        while (name != "-" && price)
        {
            int fee = price / 10;
            sum[name] += price - fee;
            name = parent[name];
            price = fee;
        }
    }

    for (int i = 0; i < enroll.size(); ++i)
    {
        answer.push_back(sum[enroll[i]]);
    }

    return answer;
}