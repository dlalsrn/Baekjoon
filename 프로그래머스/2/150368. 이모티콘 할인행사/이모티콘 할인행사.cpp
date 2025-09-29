// 이모티콘 할인행사
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> discount = { 10, 20, 30, 40 };
vector<int> totalDiscount;

int maxUser = 0;
int maxBuy = 0;

void BackTrack(vector<vector<int>>& users, vector<int> emoticons, int cnt)
{
    if (cnt == emoticons.size())
    {
        int emoPlusCnt = 0; // 이모티콘 플러스 구매 유저 수
        int emoBuy = 0; // 이모티콘 단독 구매 가격

        for (int i = 0; i < users.size(); i++)
        {
            int buyDiscount = users[i][0]; // i번 유저의 희망 할인율
            int emoPlus = users[i][1]; // 이모티콘 플러스 구매 한계치
            int totalMoney = 0; // 이모티콘의 총 가격
            bool isBuyPlus = false;

            for (int j = 0; j < emoticons.size(); j++)
            {
                if (buyDiscount <= totalDiscount[j]) // 희망 할인율보다 판매 할인율이 높으면 구매
                {
                    totalMoney += emoticons[j] * (1.0f - (totalDiscount[j] / 100.0f));
                }

                if (totalMoney >= emoPlus)
                {
                    emoPlusCnt++;
                    isBuyPlus = true;
                    break;
                }
            }

            if (!isBuyPlus)
            {
                emoBuy += totalMoney;
            }
        }

        if (maxUser < emoPlusCnt)
        {
            maxUser = emoPlusCnt;
            maxBuy = emoBuy;
        }
        else if (maxUser == emoPlusCnt)
        {
            maxBuy = max(maxBuy, emoBuy);
        }

        return;
    }

    for (int k = 0; k < discount.size(); k++)
    {
        totalDiscount.push_back(discount[k]);
        BackTrack(users, emoticons, cnt + 1);
        totalDiscount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;

    BackTrack(users, emoticons, 0);

    answer.push_back(maxUser);
    answer.push_back(maxBuy);

    return answer;
}