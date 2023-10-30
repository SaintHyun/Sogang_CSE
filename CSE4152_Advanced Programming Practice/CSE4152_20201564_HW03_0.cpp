#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int matrix[n + 10][n + 10] = {0, };
    int i, j, k;
    /*for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            int tmp;
            cin >> matrix[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = n; j >= 2; j--)
        {
            matrix[i][j] -= matrix[i][j - 1];
        }
    }*/
    for (k = 1; k <= n; k++)
    {
        int r1, r2, c1, c2, v;
        cin >> r1 >> r2 >> c1 >> c2 >> v;
        for (i = r1; i <= r2; i++)
        {
            matrix[i][c1] += v;
            matrix[i][c2 + 1] -= v;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 2; j <= n; j++)
        {
            matrix[i][j] += matrix[i][j - 1];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
