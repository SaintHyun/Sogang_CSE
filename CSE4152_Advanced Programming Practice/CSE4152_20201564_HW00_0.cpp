#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int* arr;
	int n = 0, i, max1 = 0, max2 = 0;
	cin >> n;
	arr = (int*)malloc(sizeof(int) * (n + 5));
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < n; i++)
	{
		max1 = max(0, max1 + arr[i]);
		max2 = max(max2, max1);
	}
	cout << max2;
	free(arr);
}