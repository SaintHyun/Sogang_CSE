#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, cur;
        queue<int> A;
        stack<int> B;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            A.push(tmp);
        }
        cur = 1;
        while (!A.empty() || !B.empty())
        {
            if (!A.empty() && A.front() == cur)
            {
                A.pop();
                cur++;
            }
            else if (!B.empty() && B.top() == cur)
            {
                B.pop();
                cur++;
            }
            else if (B.empty() || B.top() != cur)
            {
                B.push(A.front());
                A.pop();
            }

            if (A.empty())
            {
                if (!B.empty() && B.top() != cur)
                {
                    cout << "IMPOSSIBLE\n";
                    break;
                }
            }
        }
        if (cur == n + 1)
            cout << "POSSIBLE\n";
    }
}