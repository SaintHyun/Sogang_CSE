#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, i;
    vector<int> a;
    cin >> n;
    for (i = 0; i < n * n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), greater<int>());
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}