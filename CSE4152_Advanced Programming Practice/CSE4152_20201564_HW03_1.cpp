#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<double> angle;
    double first, pi = (double)acos(-1), maxx = -1;
    bool flag = false;
    int over = 0, under = 0;
    cin >> n;
    int i, j, k;
    double tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    first = (double)acos(tmp1 / (sqrt(tmp1 * tmp1 + tmp2 * tmp2)));
     if (tmp2 < 0)
    {
        first = 2 * pi - first;
    }
    angle.push_back(0);
    for (i = 1; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        double tmpang = (double)acos(tmp1 / (sqrt(tmp1 * tmp1 + tmp2 * tmp2)));
        if (tmp2 < 0)
        {
            tmpang = 2 * pi - tmpang;
        }
        if(tmpang - first < 0) angle.push_back(tmpang-first+2*pi);
        else angle.push_back(tmpang - first);
    }
    if (n <= 2)
    {
        cout << "HCP\n";
        return 0;
    }
    /*for (i = 0; i < n; i++)
    {
        cout << angle[i] << " ";
    }
    cout << "\n";*/

    for (i = 1; i < n; i++)
    {
        if (maxx < angle[i] && angle[i] <= pi)
            maxx = angle[i];
    }

    if (maxx == -1)
        flag = true;

    else if (maxx == pi)
    {
        for (i = 1; i < n; i++)
        {
            if (angle[i] < pi)
                under++;
            else if (angle[i] > pi)
                over++;
        }
        if (under * over == 0)
            flag = true;
        else
            flag = false;
    }
    else if (maxx < pi)
    {
        for (i = 1; i < n; i++)
        {
            if (!(angle[i] + (pi - maxx) >= 2 * pi || angle[i] <= maxx))
            {
                flag = false;
                break;
            }
        }
        if (i == n)
            flag = true;
    }

    if (flag)
        cout << "HCP\n";
    else
        cout << "NO HCP\n";
}