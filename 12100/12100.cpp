#include <iostream>
int N;
int max_val;

using namespace std;
void	up(int** &map, int &val)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[j][i])
			{
				for (int k = j + 1; k < N; k++)
				{
					if(map[j][i] == map[k][i])
					{
						map[j][i] *= 2;
						if (val < map[j][i])
							val = map[j][i];
						map[k][i] = 0;
						j = k;
						break;
					}
					else if (map[k][i])
					{
						j = k -1;
						break;
					}	
				}
			}
		}
		for (int j = 1; j < N; j++)
		{
			if (map[j][i])
			{
				for (int k = 0; k < j; k++)
				{
					if (!map[k][i])
					{
						map[k][i] = map[j][i];
						map[j][i] = 0;
						break;
					}
				}
			}
		}
	}
}
void	down(int** &map, int &val)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (map[j][i])
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if(map[j][i] == map[k][i])
					{
						map[j][i] *= 2;
						if (val < map[j][i])
							val = map[j][i];
						map[k][i] = 0;
						j = k;
						break;
					}
					else if (map[k][i])
					{
						j = k + 1;
						break;
					}	
				}
			}
		}
		for (int j = N - 2; j >= 0; j--)
		{
			if (map[j][i])
			{
				for (int k = N - 1; k > j; k--)
				{
					if (!map[k][i])
					{
						map[k][i] = map[j][i];
						map[j][i] = 0;
						break;
					}
				}
			}
		}
	}
}
void	left(int** &map, int &val)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j])
			{
				for (int k = j + 1; k < N; k++)
				{
					if(map[i][j] == map[i][k])
					{
						map[i][j] *= 2;
						if (val < map[i][j])
							val = map[i][j];
						map[i][k] = 0;
						j = k;
						break;
					}
					else if (map[i][k])
					{
						j = k -1;
						break;
					}	
				}
			}
		}
		for (int j = 1; j < N; j++)
		{
			if (map[i][j])
			{
				for (int k = 0; k < j; k++)
				{
					if (!map[i][k])
					{
						map[i][k] = map[i][j];
						map[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void	right(int** &map, int &val)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (map[i][j])
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if(map[i][j] == map[i][k])
					{
						map[i][j] *= 2;
						if (val < map[i][j])
							val = map[i][j];
						map[i][k] = 0;
						j = k;
						break;
					}
					else if (map[i][k])
					{
						j = k + 1;
						break;
					}	
				}
			}
		}
		for (int j = N - 2; j >= 0; j--)
		{
			if (map[i][j])
			{
				for (int k = N - 1; k > j; k--)
				{
					if (!map[i][k])
					{
						map[i][k] = map[i][j];
						map[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}
void func(int **map, int lev, int val);
void	push_map(int** &map, int** &copy, int lev,int &val)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			copy[i][j] = map[i][j];
	}
	// right(copy, val);
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	{
	// 		cout << copy[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	if (lev == 0)
	{
		up(copy, val);
		// if (val != 0)
		// 	func(copy, lev + 1, val);
	}
	else if (lev == 1)
	{
		down(copy, val);
		// if (val != 0)
		// 	func(copy, lev + 1, val);
	}
	else if (lev == 2)
	{
		left(copy, val);
		// if (val != 0)
		// 	func(copy, lev + 1, val);
	}
	else if (lev == 3)
	{
		right(copy, val);
		// if (val != 0)
		// 	func(copy, lev + 1, val);
	}
}

void func(int **map, int lev, int val)
{
	if (lev == 5)
	{
		if (max_val < val)
			max_val = val;
		return ;
	}
	int **map2 = new int*[N];
	for (int i = 0; i < N; i++)
	{
		map2[i] = new int[N];
		for (int j = 0; j < N; j++)
			map2[i][j] = map[i][j];
	}
	// int i =0;
	// push_map(map, map2, i,val);
	for (int i = 0; i < 4; i++)
	{
		push_map(map, map2, i,val);
		func(map2, lev + 1, val);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N;
	int val =0;
	int **map = new int *[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (val < map[i][j])
				val = map[i][j];
		}
	}
	func(map, 0, val);
	cout << max_val;
}