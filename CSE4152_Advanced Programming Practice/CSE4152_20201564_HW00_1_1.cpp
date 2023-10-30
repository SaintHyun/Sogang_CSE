#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int> > coin;
vector<vector<int> > ans;
vector<int> tmpans;
int tot;

bool compare(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

void q(int cnt, int cur)
{
    if (cur > m)
        return;
    int i;
    if (cur == m)
    {
        ans.push_back(tmpans);
        tot++;
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (coin[i].second >= 1 && ((cnt >= 1 && tmpans[tmpans.size() - 1] >= coin[i].first) || cnt == 0))
        {
            coin[i].second -= 1;
            tmpans.push_back(coin[i].first);
            q(cnt + 1, cur + coin[i].first);
            coin[i].second += 1;
            tmpans.erase(tmpans.end() - 1);
        }
    }
}

int main()
{
    int i, j;
    int coina, coinb;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> coina >> coinb;
        coin.push_back(make_pair(coina, coinb));
    }
    sort(coin.begin(), coin.end(), greater<pair<int, int> >());
    q(0, 0);
    cout << tot << "\n";
    sort(ans.begin(), ans.end(), compare);
    for (i = 0; i < tot; i++)
    {
        for (j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}