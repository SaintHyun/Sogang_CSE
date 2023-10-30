#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maze[1010][1010];
int n, m, k;
int starty, startx;
int ans;
string tmpline;

void q(int y, int x, int cnt)
{
    if (y < 1 || x < 1 || y > n || x > m)
        return;
    if (maze[y][x] == 1)
        return;
    if (maze[y][x] == 2 && cnt == k)
    {
        ans++;
        return;
    }
    if (maze[y][x] == 2 && cnt != k)
        return;
    if (cnt >= k)
        return;
    q(y + 1, x, cnt + 1);
    q(y - 1, x, cnt + 1);
    q(y, x + 1, cnt + 1);
    q(y, x - 1, cnt + 1);

    q(y - 2, x - 1, cnt + 1);
    q(y - 2, x + 1, cnt + 1);
    q(y - 1, x - 2, cnt + 1);
    q(y + 1, x - 2, cnt + 1);
    q(y + 2, x + 1, cnt + 1);
    q(y + 2, x - 1, cnt + 1);
    q(y - 1, x + 2, cnt + 1);
    q(y + 1, x + 2, cnt + 1);
}

int main()
{
    int i, j;
    cin >> n >> m >> k;
    cin.ignore();
    for (i = 1; i <= n; i++)
    {
        getline(cin, tmpline);
        for (j = 0; j < 2 * m; j += 2)
        {
            if (tmpline[j] == 'S')
            {
                maze[i][j / 2 + 1] = 0;
                starty = i;
                startx = j / 2 + 1;
            }
            else if (tmpline[j] == 'E')
                maze[i][j / 2 + 1] = 2;
            else if (tmpline[j] == '0')
                maze[i][j / 2 + 1] = 0;
            else if (tmpline[j] == '1')
                maze[i][j / 2 + 1] = 1;
        }
        tmpline.clear();
    }
    q(starty, startx, 0);
    cout << ans << "\n";
}