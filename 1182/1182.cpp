#include <iostream>
using namespace std;
int num,sum;
int count;
int **map;
void func(int j, int lev, int sum_all)
{
	int a = 0;
	if (sum_all == sum && lev != 0)
	{
		count++;
	}
	if (j >= num)
		return;
	if (lev == num)
		return;
	for (int i = j; i < num; i++)
	{
		if (map[1][i] == 0)
		{
			a = map[0][i] + sum_all;
			map[1][i] = 1;
			func(i + 1 ,lev + 1, a);
			map[1][i] = 0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> num >> sum;
	map = new int*[2];
	map[0] = new int[num];
	map[1] = new int[num];
	for (int i = 0; i < num ; i++)
	{
		cin >> map[0][i];
		map[1][i] = 0;
	}
	func(0, 0, 0);

	cout << count;
}