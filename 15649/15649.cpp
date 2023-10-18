#include <iostream>
using namespace std;

int max_a;
int l;
void	select_num(int *use, int count,int *res)
{
	if (count == l)
	{
		for(int i = 0; i < l; i++)
			cout << res[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < max_a ; i++)
	{
		if (use[i] == 0)
		{
			res[count] = i + 1;
			use[i] = 1;
			select_num(use,count + 1,res);
			use[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> max_a >> l;
	int *use = new int[max_a];
	int *res = new int[l];
	for (int i = 0; i < max_a; i++)
		use[i] = 0;
	int count = 0;
	select_num(use,count,res);
}
