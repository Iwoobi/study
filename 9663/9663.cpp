#include <iostream>
using namespace std;
int count;
int a;
int check_map(bool **map, int x, int y)
{
	for(int i = 0; i < x; i++)
	{
		if (map[i][y])
			return 1;
		if (y + x - i < a)
		{
			if (map[i][y + x - i])
				return 1;
		}
		if(y - x + i >= 0)
		{
			if (map[i][y - x + i])
				return 1;
		}
	}
	return 0;
}

void	func(int mod, bool **map)
{
	if (mod == a)
	{
		count++;
		return ;
	}
	for(int i = 0; i < a; i++ )
	{
		map[mod][i] = 1;
		if (!check_map(map, mod, i))
			func(mod +1, map);
		map[mod][i] = 0;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a;
	bool **map = new bool*[a];
	for(int i =0; i < a; i++)
	{
		map[i] = new bool[a];
		for (int j = 0; j < a; j++)
			map[i][j] = 0;	
	}
	func(0, map);
	cout << count;
}