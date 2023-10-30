#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, i, j, tmp, k;
    cin >> n;
    vector<int> a[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }
    cin >> k;
    int y = 0, x = n - 1;
    while (a[y][x] != k)
    {
        if (a[y][x] < k)
            y++;
        else if (a[y][x] > k)
            x--;
        if (y > n - 1 || x < 0)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << y + 1 << " " << x + 1 << "\n";
}