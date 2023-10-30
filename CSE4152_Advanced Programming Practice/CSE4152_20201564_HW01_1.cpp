#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int i, j, k;
    int n;
    int *dp;
    set<int> tmp;
    cin >> n;
    vector<set<int> > path[n + 1];

    tmp.insert(1);
    path[1].push_back(tmp);
    tmp.insert(2);
    path[2].push_back(tmp);

    dp = new int[n + 2];
    dp[1] = 0;
    dp[2] = 1;

    for (i = 3; i <= n; i++)
    {
        int minn = 999999999;
        for (j = 1; j <= i / 2; j++)
        {
            for (k = 0; k < (int)path[i - j].size(); k++)
            {
                set<int>::iterator iter = path[i - j][k].find(j);
                if (iter != path[i - j][k].end())
                {
                    if (minn > dp[i - j] + 1)
                        minn = dp[i - j] + 1;
                }
            }
        }
        dp[i] = minn;
        for (j = 1; j <= i / 2; j++)
        {
            for (k = 0; k < (int)path[i - j].size(); k++)
            {
                set<int>::iterator iter = path[i - j][k].find(j);
                if (iter != path[i - j][k].end())
                {
                    if (minn == dp[i - j] + 1)
                    {
                        set<int> temp(path[i - j][k]);
                        temp.insert(i);
                        path[i].push_back(temp);
                    }
                }
            }
        }
    }
    cout << dp[n] << " ";
    set<int>::iterator iter;
    for (i = 0; i < 1; i++)
    {
        for (iter = path[n][i].begin(); iter != path[n][i].end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << "\n";
    }

    // cout << "\n";
    return 0;
}